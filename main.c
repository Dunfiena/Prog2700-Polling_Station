#include <stdio.h>
#include <stdbool.h>
#include <String.h>
#include <stdlib.h>

struct Voter{
    int voterID;
    char FirstName[50];
    char LastName[50];
    long RegistrationNumber;
    int DoB;
    bool hasVoted;
} ;
struct Admin{
    char FirstName[50];
    char LastName[50];
    char LoginID[50];
    char Password[16];
};
struct PollingOfficer{
    char FirstName[50];
    char LastName[50];
    char LoginID[50];
    char Password[16];
};
struct Candidate{
    char FirstName[50];
    char LastName[50];
    int Votes;
};
int main() {
    int path, n;
    bool flag=true;
    struct voter *voters=(struct voter*)malloc(n*sizeof(struct Voter));
    while (flag == true) {
        int entry;
        printf("Welcome to the voter registration kiosk\n "
               "Please enter your 8 digit Voter Registration Number");
        scanf("%d", &entry);
        if (entry==1) {
            //path for log in for PO and Admin
            printf("\nPlease select path. (1) Polling Officer (2) System Admin (3) Cancel");
            scanf("%d", &path);

            //Polling officer stuff (path1)
            if (path == 1) {
                printf("\nPlease select option: (1) Register Voter (2)Declare Results (3) Cancel");
                scanf("%d", &path);
                if (path==1){
                    //enter voter
                    for(int personNum=0;personNum<n;personNum++){
                        struct Voter n;
                        printf("\nPlease enter voter's First Name");
                        scanf("%s",n.FirstName);
                        printf("\nPlease enter voter's Last Name");
                        scanf("%s",n.LastName);
                        printf("\nPlease enter voter's Date of Birth (as yyyymmdd");
                        scanf("%d",&n.DoB);
                        n.RegistrationNumber=11223344;
                    }
                }else if(path==2){
                    //END OF SESSION RESULTS OUTPUT
                    printf("\nDeclaring the results will end the session. Would you like to proceed? (1) yes (2) no");
                    scanf("%d", &path);
                    if(path==1){
                        flag=false;
                    }
                }
                //System Admin path
            } else if (path == 2) {

            }

            //Checking voter validation
        } else {


            }
        }
    return 0;
    }