/* 
https://github.com/KodeNewbie 
https://www.linkedin.com/in/sakshamsinghaeie/
*/

#include <stdio.h>

int pin = 1234, pinEntry = 1, note500 = 10, note100 = 20;
double accBal = 25000;

int ATMOperations();
int withdrawal();
int balanceCheck();
int pinChange();
int pinVerification();

int withdrawal()
{
    printf("\nAvailable Denomination : ");
    if (note500 >= 1 && note100 >= 1)
    {
        printf(" 500   100");
    }
    else if (note500 == 0 && note100 >= 1)
    {
        printf(" 100 ");
    }
    else if (note500 >= 1 && note100 == 0)
    {
        printf(" 500 ");
    }
    else
    {
        printf("\nError : Zero funds in ATM. Visit nearby ATM.");
    }
    
    long int wtdAmount;

    if (note500 >= 1 || note100 >= 1)
    {
        printf("\nEnter the amount you want to withdraw : ");
        scanf("%ld", &wtdAmount );

        if (wtdAmount <= accBal && wtdAmount % 100 == 0)
        {
            int required500 = wtdAmount / 500 ;
            if (required500 > note500)
            {
                required500 = note500 ;
            }
            
            int required100 = ( wtdAmount - required500 * 500 ) / 100 ;

            if ( required100 <= note100 )
            {
                printf("\nCollect your cash. Thank You.");
                printf("\nCashbox => %d :500 note(s) and %d :100 note(s).", required500, required100);
                accBal -= wtdAmount ;
                note500 -= required500;
                note100 -= required100; 
                printf("\nYour remaining account balance : %.2lf", accBal);
            }
            else
            {
                printf("\nError : Machine does not have enough cash left to support your withdraw amount. ");
            }
                        
        }
        else if (wtdAmount <= accBal && wtdAmount % 100 != 0)
        {
            printf("\nError : Invalid amount. Denominations not available.");
        }
        else
        {
            printf("\nError : Insufficient funds in your account.");
        }
        
    }
    else
    {
        printf("\nInsuffficient funds available at this ATM.");
    }

    return ATMOperations();
}

int balanceCheck()
{
    printf("\nYour account balance : %.2lf",accBal);
    return ATMOperations();
}

int pinChange()
{
    int newPin ;
    printf("\nEnter new 4 digit PIN : ");
    scanf("%d", &newPin);

    if (newPin >= 1000 && newPin <= 9999)
    {
        pin = newPin ;    
        printf("\nPIN changed successfully.");
    }
    else
    {
        printf("\nError : Invalid new PIN.");
        return pinChange() ;
    }
    
    return ATMOperations();
}


int ATMOperations()
{
    char option;
    printf("\n\nSelect an operations : ");
    printf("\n1. Cash Withdrawal ");
    printf("\n2. Balance Check ");
    printf("\n3. Pin Change ");
    printf("\n4. Cancel Session\n ");
    scanf(" %c", &option);

    switch (option)
    {
    case '1':
        withdrawal();
        break;
    
    case '2':
        balanceCheck();
        break;
    
    case '3':
        pinChange();
        break;

    case '4':
        break;
    
    default:
        printf("\nError : Invalid Option");
        ATMOperations;
        break;
    }
    return 0;
}


int pinVerification()
{
    int inpPin;
    printf("\nEnter 4 digit pin : ");
    scanf("%d", &inpPin);

    if ( inpPin == pin && pinEntry <= 2)
    {
        ATMOperations();
    }
    else if (inpPin != pin && pinEntry <= 2)
    {
        printf("\nError : Wrong Pin.");
        pinEntry++ ;
        pinVerification();
    }
    else
    {
        printf("\nMaximum attempts of wrong Pin. Session ended.");
    }
    return 0;
}

int main()
{
    printf("\nWelcome to ATM");
    pinVerification();
    printf("\nThank You ! Have a nice day !");
    return 0 ;
}


