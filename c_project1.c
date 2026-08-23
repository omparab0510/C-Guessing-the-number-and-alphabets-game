#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int number, guess = 0, guessed;
    int range, n = 15, valid, guessmode;
    char choice[20], alphabets, guessedalphabets, real = alphabets, m;
    int score = 0;
    time_t start, end;
    double time_taken;

    srand(time(0));

    do
    {

        // choose mode
        printf("~~~~~~~~~~~~~~~(:Guessing game:)~~~~~~~~~~~~~~~\n");

        do
        {
            printf("Choose mode. \n");
            printf("1. Guess the Number\n");
            printf("2. Guess the Alphabet\n");
            printf("Enter number: \n");
            scanf("%d", &guessmode);

            if (guessmode != 1 && guessmode != 2)
            {
                printf("Invalid mode! Try again.\n");
            }
        } while (guessmode != 1 && guessmode != 2);

        printf("\nChoose difficulty:\n");

        if (guessmode == 1)
        {
            printf("1. Easy   (number under 100)\n");
            printf("2. Medium (number under 500)\n");
            printf("3. Hard   (number under 1000)\n");
            printf("4. Expert (number under 10000)\n");
        }
        else
        {
            printf("1. Easy   (15 guesses)\n");
            printf("2. Medium (10 guesses)\n");
            printf("3. Hard   (8 guesses)\n");
            printf("4. Expert (6 guesses)\n");
        }

        if (guessmode == 1)
        {

            do
            {
                valid = 1;

                printf("Enter choice: ");
                scanf("%s", choice);

                // loop for choosing difficulty level
                for (int i = 0; choice[i]; i++)
                {
                    choice[i] = tolower(choice[i]);
                }

                if (strcmp(choice, "1") == 0 || strcmp(choice, "easy") == 0)
                {
                    range = 100;
                    n = 15;
                }
                else if (strcmp(choice, "2") == 0 || strcmp(choice, "medium") == 0)
                {
                    range = 500;
                    n = 15;
                }
                else if (strcmp(choice, "3") == 0 || strcmp(choice, "hard") == 0)
                {
                    range = 1000;
                    n = 15;
                }
                else if (strcmp(choice, "4") == 0 || strcmp(choice, "expert") == 0)
                {
                    range = 10000;
                    n = 15;
                }
                else
                {
                    printf("Invalid choice, try again.\n");
                    valid = 0;
                }
            } while (valid == 0);

            start = time(NULL);

            number = (rand() % range) + 1;

            printf("Guess the number under %d\n", range);
            printf("You have %d guesses.\n", n);

            // loop for attempts
            guess = 0;

            do
            {
                printf("Attempt %d/%d - Enter your guess:", guess + 1, n);
                scanf("%d", &guessed);

                if (guessed > number)
                {
                    printf("Enter lower number. Try again.\n");
                }
                else if (guessed < number)
                {
                    printf("Enter higher number. Try again.\n");
                }
                else
                {
                    printf("Congratulations! You guessed the number.\n");
                }
                guess++;

                if (guess == 3)
                {
                    if (number % 2 == 0)
                    {
                        printf("Hint: The number is even.\n");
                    }
                    else
                    {
                        printf("Hint: The number is odd.\n");
                    }
                }

                if (guess == 8)
                {
                    if (number % 5 == 0)
                    {
                        printf("Hint: The number is divisible by 5.\n");
                    }
                    else
                    {
                        printf("Hint: The number is not divisible by 5.\n");
                    }
                }

                if (guess == 12)
                {
                    if (number % 2 == 0)
                    {
                        printf("Hint: The number is divisible by 2.\n");
                    }
                    else
                    {
                        printf("Hint: The number is not divisible by 2.\n");
                    }
                }

            } while (guessed != number && guess < n);

            end = time(NULL);
            time_taken = difftime(end, start);

            if (guessed == number)
            {
                printf("Congratulations! you guessed the number.\n");
                printf("Time taken: %.0f seconds\n", time_taken);

                if (time_taken <= 30)
                {
                    printf("Score: 1000 points\n");
                }
                else if (time_taken <= 60)
                {
                    printf("Score: 500 points\n");
                }
                else if (time_taken <= 90)
                {
                    printf("Score: 300 points\n");
                }
                else
                {
                    printf("Score: 0 points\n");
                }
            }
            else
            {
                printf("Game over! The number is %d.\n", number);
                printf("Score: 0 points\n");
            }
        }

        // guessing the alphabets

        else if (guessmode == 2)
        {

            do
            {

                valid = 1;

                printf("Enter choice: ");
                scanf("%s", choice);

                if (strcmp(choice, "1") == 0 || strcmp(choice, "easy") == 0)
                {
                    n = 15;
                }
                else if (strcmp(choice, "2") == 0 || strcmp(choice, "medium") == 0)
                {
                    n = 10;
                }
                else if (strcmp(choice, "3") == 0 || strcmp(choice, "hard") == 0)
                {
                    n = 8;
                }
                else if (strcmp(choice, "4") == 0 || strcmp(choice, "expert") == 0)
                {
                    n = 6;
                }
                else
                {
                    printf("Invalid choice, try again.\n");
                    valid = 0;
                }
            } while (valid == 0);

            start = time(NULL);

            alphabets = 'a' + rand() % 26;
            real = alphabets;

            printf("Guess the alphabets in %d attempts\n", n);

            guess = 0;
            do
            {
                printf("Attempt %d/%d - Enter your guess:", guess + 1, n);
                scanf(" %c", &guessedalphabets);

                if (guessedalphabets > real)
                {
                    printf("Enter lower alphabet. Try again.\n");
                }
                else if (guessedalphabets < real)
                {
                    printf("Enter higher alphabet. Try again.\n");
                }
                else
                {
                    printf("Congratulations! You guessed the alphabets.\n");
                }
                guess++;

                if (guess == 3)
                {
                    if (real >= 'a' && real <= 'm')
                    {
                        printf("Hint: The alphabet is between a and m.\n");
                    }
                    else
                    {
                        printf("Hint: The alphabet is between n and z.\n");
                    }
                }

                if (guess == 8)
                {
                    if (real == 'a' || real == 'e' || real == 'i' || real == 'o' || real == 'u')
                    {
                        printf("Hint: The alphabet is a vowel.\n");
                    }
                    else
                    {
                        printf("Hint: The alphabet is a consonant.\n");
                    }
                }

            } while (guessedalphabets != real && guess < n);

            end = time(NULL);
            time_taken = difftime(end, start);

            if (guessedalphabets == real)
            {
                printf("You guessed the alphabet in %d guesses\n", guess);
                printf("Time taken: %.0f seconds\n", time_taken);

                if (time_taken <= 30)
                {
                    printf("Score: 1000 points\n");
                }
                else if (time_taken <= 60)
                {
                    printf("Score: 500 points\n");
                }
                else if (time_taken <= 90)
                {
                    printf("Score: 300 points\n");
                }
                else
                {
                    printf("Score: 0 points\n");
                }
            }
            else
            {
                printf("Game over! The alphabet is %c.\n", real);
                printf("Score: 0 points\n");
            }
        }

        printf("Do you want to play again?(y/n) ");
        scanf(" %c", &m);
    } while (m == 'y');

    {
        printf("Thank you. Please visit again!!");
    }

    return 0;
}
