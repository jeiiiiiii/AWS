using System.Collections;
using UnityEngine;
using TMPro;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class RockPaperScissors : MonoBehaviour
{
    public TextMeshProUGUI dialogueText;  // For general dialogue
    public TextMeshProUGUI alfdialogueText;  // For Alf's dialogue
    public TextMeshProUGUI alfinadialogueText; // For Alfina's dialogue
    public TextMeshProUGUI alfreddialogueText; // For Alfred's dialogue
    public TextMeshProUGUI playerScoreText;   // Player's score text
    public TextMeshProUGUI MascotScore; // Computer's score text
    public TextMeshProUGUI tieScoreText;      // Tie score text

    public Button restart;
    public Button nextButton;
    public Button alfButton;
    public Button alfMascotButton;
    public Button alfinaButton;
    public Button alfinaMascotButton;
    public Button alfredButton;
    public Button alfredMascotButton;
    public Button rockButton;
    public Button paperButton;
    public Button scissorsButton;

    public Button winButton;
    public Button yesalfButton;
    public Button yesalfredButton;
    public Button yesalfinaButton;
    public Button noButton;
    public Button ChooseAnotherButton;

    private int playerScore = 0;
    private int computerScore = 0;
    private int tieScore = 0;
    private int currentRound = 0;
    private int totalRounds = 5;

    private string[] dialogueLines;
    private string[] alfdialogueLines;
    private string[] alfinadialogueLines;
    private string[] alfreddialogueLines;

    private string[] choices = { "Rock", "Paper", "Scissors" };
    private int currentDialogueIndex = 0;

    void Start()
    {
        if (SceneManager.GetActiveScene().name == "ChooseOpponentScene")
        {
            dialogueLines = new string[]
            {
                "Hello, AWStronaut.",
                "Before we start our game, Please select your opponent in your mind.",
                "Have a great game and good luck.",
                "Please select your opponent!"
            };
            dialogueText.text = dialogueLines[currentDialogueIndex];
            nextButton.onClick.AddListener(ShowNextDialogue);
            alfButton.onClick.AddListener(OnAlfButtonClick);
            alfinaButton.onClick.AddListener(OnAlfinaButtonClick);
            alfredButton.onClick.AddListener(OnAlfredButtonClick);

            winButton.onClick.AddListener(Win);

            alfButton.gameObject.SetActive(false);
            alfinaButton.gameObject.SetActive(false);
            alfredButton.gameObject.SetActive(false);

            alfMascotButton.interactable = false;
            alfinaMascotButton.interactable = false;
            alfredMascotButton.interactable = false;

        }
        else if (SceneManager.GetActiveScene().name == "AlfScene")
        {
            alfdialogueLines = new string[]
            {
                "Hi, I'm Alf! Welcome to the AWS Cloud Club game! \nLet's have some fun with Rock, Paper, Scissors! Are you ready?",
            };

            alfdialogueText.text = alfdialogueLines[currentDialogueIndex];
            nextButton.onClick.AddListener(ShowNextAlfDialogue);

            rockButton.onClick.AddListener(() => OnPlayerChoice("Rock"));
            paperButton.onClick.AddListener(() => OnPlayerChoice("Paper"));
            scissorsButton.onClick.AddListener(() => OnPlayerChoice("Scissors"));

            dialogueText.gameObject.SetActive(false);

            rockButton.gameObject.SetActive(false);
            paperButton.gameObject.SetActive(false);
            scissorsButton.gameObject.SetActive(false);

            playerScoreText.gameObject.SetActive(false);
            MascotScore.gameObject.SetActive(false);
            tieScoreText.gameObject.SetActive(false);

            ChooseAnotherButton.gameObject.SetActive(false);
            yesalfButton.gameObject.SetActive(false);
            noButton.gameObject.SetActive(false);
        }
        else if (SceneManager.GetActiveScene().name == "AlfinaScene")
        {
            alfinadialogueLines = new string[]
            {
                "Hey there! I’m Alfina! \nLet’s play Rock, Paper, Scissors and have a great time together!"
            };

            alfinadialogueText.text = alfinadialogueLines[currentDialogueIndex];
            nextButton.onClick.AddListener(ShowNextAlfinaDialogue);

            rockButton.onClick.AddListener(() => OnPlayerChoice("Rock"));
            paperButton.onClick.AddListener(() => OnPlayerChoice("Paper"));
            scissorsButton.onClick.AddListener(() => OnPlayerChoice("Scissors"));

            dialogueText.gameObject.SetActive(false);

            ChooseAnotherButton.gameObject.SetActive(false);
            yesalfinaButton.gameObject.SetActive(false);
            noButton.gameObject.SetActive(false);

            rockButton.gameObject.SetActive(false);
            paperButton.gameObject.SetActive(false);
            scissorsButton.gameObject.SetActive(false);

            playerScoreText.gameObject.SetActive(false);
            MascotScore.gameObject.SetActive(false);
            tieScoreText.gameObject.SetActive(false);

        }

        else if (SceneManager.GetActiveScene().name == "AlfredScene")
        {
            alfreddialogueLines = new string[]
            {
                "Hey, I’m Alfred! I love exploring new things, and Rock, Paper, Scissors is one of them! Ready for a fun match?"
            };

            alfreddialogueText.text = alfreddialogueLines[currentDialogueIndex];
            nextButton.onClick.AddListener(ShowNextAlfredDialogue);

            rockButton.onClick.AddListener(() => OnPlayerChoice("Rock"));
            paperButton.onClick.AddListener(() => OnPlayerChoice("Paper"));
            scissorsButton.onClick.AddListener(() => OnPlayerChoice("Scissors"));

            dialogueText.gameObject.SetActive(false);

            rockButton.gameObject.SetActive(false);
            paperButton.gameObject.SetActive(false);
            scissorsButton.gameObject.SetActive(false);

            playerScoreText.gameObject.SetActive(false);
            MascotScore.gameObject.SetActive(false);
            tieScoreText.gameObject.SetActive(false);

            ChooseAnotherButton.gameObject.SetActive(false);
            yesalfredButton.gameObject.SetActive(false);
            noButton.gameObject.SetActive(false);
        }

    }

    void ShowNextDialogue()
    {
        currentDialogueIndex++;
        if (currentDialogueIndex < dialogueLines.Length)
        {
            dialogueText.text = dialogueLines[currentDialogueIndex];
        }
        else
        {
            nextButton.gameObject.SetActive(false);

            alfButton.gameObject.SetActive(true);
            alfinaButton.gameObject.SetActive(true);
            alfredButton.gameObject.SetActive(true);

            alfMascotButton.interactable = true;
            alfinaMascotButton.interactable = true;
            alfredMascotButton.interactable = true;
        }
    }

    void ShowNextAlfDialogue()
    {
        currentDialogueIndex++;
        if (currentDialogueIndex < alfdialogueLines.Length)
        {
            alfdialogueText.text = alfdialogueLines[currentDialogueIndex];
        }
        else
        {
            alfdialogueText.gameObject.SetActive(false);
            nextButton.gameObject.SetActive(false);

            dialogueText.gameObject.SetActive(true);

            rockButton.gameObject.SetActive(true);
            paperButton.gameObject.SetActive(true);
            scissorsButton.gameObject.SetActive(true);

            playerScoreText.gameObject.SetActive(true);
            MascotScore.gameObject.SetActive(true);
            tieScoreText.gameObject.SetActive(true);

            ChooseAnotherButton.gameObject.SetActive(false);
            yesalfButton.gameObject.SetActive(false);
            noButton.gameObject.SetActive(false);
        }
    }

    void ShowNextAlfinaDialogue()
    {
        currentDialogueIndex++;
        if (currentDialogueIndex < alfinadialogueLines.Length)
        {
            alfinadialogueText.text = alfinadialogueLines[currentDialogueIndex];
        }
        else
        {   
            alfinadialogueText.gameObject.SetActive(false);
            nextButton.gameObject.SetActive(false);

            dialogueText.gameObject.SetActive(true);

            rockButton.gameObject.SetActive(true);
            paperButton.gameObject.SetActive(true);
            scissorsButton.gameObject.SetActive(true);

            playerScoreText.gameObject.SetActive(true);
            MascotScore.gameObject.SetActive(true);
            tieScoreText.gameObject.SetActive(true);

            ChooseAnotherButton.gameObject.SetActive(false);
            yesalfinaButton.gameObject.SetActive(false);
            noButton.gameObject.SetActive(false);

        }
    }

    void ShowNextAlfredDialogue()
    {
        currentDialogueIndex++;
        if (currentDialogueIndex < alfreddialogueLines.Length)
        {
            alfreddialogueText.text = alfreddialogueLines[currentDialogueIndex];
        }
        else
        {
            alfreddialogueText.text = "Brace yourself for a tough battle!";
            alfreddialogueText.gameObject.SetActive(false);
            nextButton.gameObject.SetActive(false);

            
            dialogueText.gameObject.SetActive(true);

            rockButton.gameObject.SetActive(true);
            paperButton.gameObject.SetActive(true);
            scissorsButton.gameObject.SetActive(true);

            playerScoreText.gameObject.SetActive(true);
            MascotScore.gameObject.SetActive(true);
            tieScoreText.gameObject.SetActive(true);

            
            ChooseAnotherButton.gameObject.SetActive(false);
            yesalfredButton.gameObject.SetActive(false);
            noButton.gameObject.SetActive(false);
        }
    }

    public void OnAlfButtonClick()
    {
        SceneManager.LoadScene("AlfScene");
    }

    public void OnAlfinaButtonClick()
    {
        SceneManager.LoadScene("AlfinaScene");
    }

    public void OnAlfredButtonClick()
    {
        SceneManager.LoadScene("AlfredScene");
    }

    public void Win()
    {
        SceneManager.LoadScene("Extra");
    }

    public void ChooseAnother()
    {
        LoadGameScene();
    }

    public void Yes()
    {
        StartGame();
        SceneManager.LoadScene("AlfScene");

    }
    public void YesAlfred()
    {
        StartGame();
        SceneManager.LoadScene("AlfredScene");
    }
    public void YesAlfina()
    {
        StartGame();
        SceneManager.LoadScene("AlfinaScene");
    }

    public void No()
    {
        SceneManager.LoadScene("LandingScene");
    }


    public void StartGame()
    {
        playerScore = 0;
        computerScore = 0;
        tieScore = 0;
        currentRound = 0;
    }
    public void RestartGame()
    {
        LoadMainMenu();
    }

    public void LoadMainMenu()
    {
        SceneManager.LoadScene("LandingScene");
    }

    public void LoadGameScene()
    {
        SceneManager.LoadScene("ChooseOpponentScene");
    }
    

    public void OnPlayerChoice(string playerChoice)
{
    if (playerScore >= 5 || computerScore >= 5)
    {
        ShowFinalResults();
        return;
    }
    
    string computerChoice = GetComputerChoice();
    string result = DetermineWinner(playerChoice, computerChoice);

    dialogueText.text = $"You chose {playerChoice}, I chose {computerChoice}. {result}";

    UpdateScoreUI();

    if (playerScore >= 5 || computerScore >= 5)
    {
        ShowFinalResults();
    }
}

    private string GetComputerChoice()
    {
        int randomIndex = Random.Range(0, choices.Length);
        return choices[randomIndex];
    }


    private void UpdateScoreUI()
    {
        playerScoreText.text = $"Player Score: {playerScore}";
        MascotScore.text = $"Mascot: {computerScore}";
    }

    private string DetermineWinner(string playerChoice, string computerChoice)
{
    if (playerScore >= 5 || computerScore >= 5)
    {
        ShowFinalResults();
        return "";
    }

    if (playerChoice == computerChoice)
    {
        return "It's a tie! Choose another!";
    }

    if ((playerChoice == "Rock" && computerChoice == "Scissors")
        || (playerChoice == "Paper" && computerChoice == "Rock")
        || (playerChoice == "Scissors" && computerChoice == "Paper"))
    {
        playerScore++;
        if (playerScore >= 5)
        {
            ShowFinalResults();
            return "";
        }
        return GetMascotLoseDialogue();
    }
    else
    {
        computerScore++;
        if (computerScore >= 5)
        {
            ShowFinalResults();
            return "";
        }
        if (computerScore == 2)
        {
            return GetMascotWinDialogue() + "\n" + GetMascotMotivateDialogue();
        }

        return GetMascotWinDialogue();
    }
}


    private string GetMascotWinDialogue()
    {
        if (SceneManager.GetActiveScene().name == "AlfScene")
            return $"\nYes! I won this round! The score is now {computerScore}-{playerScore}! Keep going, you got this!";
        else if (SceneManager.GetActiveScene().name == "AlfinaScene")
            return $"\nHehe! I won this round! The score is now {computerScore}-{playerScore}! You’re really good at this!";
        else if (SceneManager.GetActiveScene().name == "AlfredScene")
            return $"\nYes! I won this round! The score is now {computerScore}-{playerScore}! Let’s see what happens next!";
        return "You win!";
    }

        private string GetMascotLoseDialogue()
    {
        if (SceneManager.GetActiveScene().name == "AlfScene")
            return $"\nOh no! You got me! The score is now {computerScore}-{playerScore}. You're a tough opponent!";
        else if (SceneManager.GetActiveScene().name == "AlfinaScene")
            return $"\nAww, you beat me! The score is now {computerScore}-{playerScore}. You’re amazing!";
        else if (SceneManager.GetActiveScene().name == "AlfredScene")
            return $"\nWhoa! You beat me! The score is now {computerScore}-{playerScore}. You’re quite the strategist!";
        return "You lose! Better luck next time!";
    }

        private string GetMascotMotivateDialogue()
    {
        if (SceneManager.GetActiveScene().name == "AlfScene")
            return "Keep going! Every challenge makes you better. You can still turn this around!";
        else if (SceneManager.GetActiveScene().name == "AlfinaScene")
            return "You got this! I believe in you! Let’s keep playing and see who wins!";
        else if (SceneManager.GetActiveScene().name == "AlfredScene")
            return "Every game is an experiment! Try something new and see what works. Let’s keep going!";
        return "You lose! Better luck next time!";
    }

    
public void ShowFinalResults()
    {
        if (playerScore > computerScore)
        {
            dialogueText.text = $"Congratulations! You won the game! {computerScore}-{playerScore} \n" + GetMascotContinueDialogue();

        }
        else if (computerScore > playerScore)
        {
            dialogueText.text = $"You lost! Better luck next time! {computerScore}-{playerScore} \n" + GetMascotContinueDialogue();
        }
        else
        {
            dialogueText.text = $"It's a draw! {computerScore}-{playerScore} \n" + GetMascotContinueDialogue();
        }

        rockButton.gameObject.SetActive(false);
        paperButton.gameObject.SetActive(false);
        scissorsButton.gameObject.SetActive(false);

        ChooseAnotherButton.gameObject.SetActive(true);
        noButton.gameObject.SetActive(true);

        playerScoreText.gameObject.SetActive(false);
        MascotScore.gameObject.SetActive(false);
        tieScoreText.gameObject.SetActive(false);

        if (yesalfinaButton != null)
            yesalfinaButton.gameObject.SetActive(true);

        if (yesalfredButton != null)
            yesalfredButton.gameObject.SetActive(true);

        if (yesalfButton != null)
            yesalfButton.gameObject.SetActive(true);


    }
    private string GetMascotContinueDialogue()
        {
            if (SceneManager.GetActiveScene().name == "AlfScene")
                return "Taking a break is cool, but the best way to win is to keep trying! Wanna give it one more go?";
            else if (SceneManager.GetActiveScene().name == "AlfinaScene")
                return "That’s okay! But I’d love to play with you again. Wanna give it one more go?";
            else if (SceneManager.GetActiveScene().name == "AlfredScene")
                return "That’s fine! But every great innovator keeps trying. Maybe next time, can test new tactics?";
            return "Play again?";
        }

}
