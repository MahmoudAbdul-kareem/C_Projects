/**                       Documentation section
==========================================================================
  @file           : Library_Management_System
  @author         : Mahmoud Abdul-kareem
  @brief          : Contains the functionality of my application
==========================================================================
*/

#include "Library.h"

int main()
{
    uint8 input = 0;
    
    system("cls"); // clear screen
    printf("=========WELCOME TO E-LIBRARY=========\n");
    while (1)
    {
        printf("\n1) Add book information\n");
        printf("2) Display books information\n");
        printf("3) List all books of given author\n");
        printf("4) Number of books in the liberary\n");
        printf("5) Exit\n");

        printf("\nEnter your choice: ");
        scanf("%hhi", &input);
        // clear screen
        system("cls");

        switch (input)
        {
            case 1:
                AddBookInfo();
                break;
            case 2:
                DisplayBookInfo();
                break;
            case 3:
                ListByAuthor();
                break;
            case 4:
                NumberOfBooks();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Enter valid option from (1) to (5) \n");
                break;
        }
    }
    
    return 0;
}
