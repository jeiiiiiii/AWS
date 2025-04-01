import json
import boto3

stepfunctions_client = boto3.client('stepfunctions')

# Step Function ARN
STEP_FUNCTION_ARN = "arn:aws:states:ap-southeast-1:876497563387:stateMachine:MyStateMachine-3veljdhlv"

def lambda_handler(event, context):
    print("Event received:", json.dumps(event))
    
    # Extract ProvisionedProductId
    provisioned_product_id = event['detail']['requestParameters']['provisionedProductId']
    
    # Start Step Function Execution
    response = stepfunctions_client.start_execution(
        stateMachineArn=STEP_FUNCTION_ARN,
        input=json.dumps({"ProvisionedProductId": provisioned_product_id})
    )

    return {
        "statusCode": 200,
        "body": json.dumps({
            "message": "Step Function Execution Started",
            "executionArn": response['executionArn']
        })
    }
