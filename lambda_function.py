import json
import boto3
import time

# Initialize AWS Organizations client
org_client = boto3.client('organizations')

# Initialize IAM client
iam_client = boto3.client('iam')

def lambda_handler(event, context):
    """ AWS Lambda function to create an AWS account and set up IAM roles """
    
    # Account details sample
    account_name = "NewAWSAccount"
    email = "newaccount@example.com"
    role_name = "OrganizationAccountAccessRole"

    print(f"Creating AWS account: {account_name}")

    # account details
    response = org_client.create_account(
        Email=email,
        AccountName=account_name,
        RoleName=role_name
    )

    # Get the Account Request ID
    request_id = response['CreateAccountStatus']['Id']
    
    # Step 2: Wait for account creation to complete
    print("Waiting for account creation to complete...")
    account_id = None
    while True:
        status_response = org_client.describe_create_account_status(CreateAccountRequestId=request_id)
        status = status_response['CreateAccountStatus']['State']
        
        if status == "SUCCEEDED":
            account_id = status_response['CreateAccountStatus']['AccountId']
            print(f"Account created successfully! Account ID: {account_id}")
            break
        elif status == "FAILED":
            print(f"Account creation failed: {status_response['CreateAccountStatus']['FailureReason']}")
            return {"status": "failed", "reason": status_response['CreateAccountStatus']['FailureReason']}
        
        time.sleep(10)  # Wait and check again

    # Step 3: Assume role into the new account to set up IAM permissions
    print(f"Setting up IAM roles in account {account_id}...")
    
    sts_client = boto3.client('sts')
    assumed_role = sts_client.assume_role(
        RoleArn=f"arn:aws:iam::{account_id}:role/{role_name}",
        RoleSessionName="AccountSetupSession"
    )
    
    credentials = assumed_role['Credentials']
    
    # Use new credentials to create an IAM client for the new account
    iam_client_new_account = boto3.client(
        'iam',
        aws_access_key_id=credentials['AccessKeyId'],
        aws_secret_access_key=credentials['SecretAccessKey'],
        aws_session_token=credentials['SessionToken']
    )
    
    # Create an IAM role in the new account (example role)
    role_policy = {
        "Version": "2012-10-17",
        "Statement": [
            {
                "Effect": "Allow",
                "Principal": {"Service": "ec2.amazonaws.com"},
                "Action": "sts:AssumeRole"
            }
        ]
    }
    
    iam_client_new_account.create_role(
        RoleName="EC2InstanceRole",
        AssumeRolePolicyDocument=json.dumps(role_policy)
    )

    print("IAM role created successfully in new account.")
    
    return {
        "status": "success",
        "account_id": account_id
    }

