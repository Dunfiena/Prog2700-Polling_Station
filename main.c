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
};
struct Admin{
    int AdminID;
    char LoginID[50];
    char Password[16];
};
struct PollingOfficer{
    int officerID;
    char FirstName[50];
    char LastName[50];
    char Password[16];
};
struct Candidate{
    int candidateID;
    char FirstName[50];
    char LastName[50];
    int Votes;
};
int main() {
    struct Voter v[100];
    struct PollingOfficer po[3];
    struct Admin sa[1];
    struct Candidate c[5];
    char userentry[50], userentry2[50], userentry3[50];
    int path, n, result, result2, result3;
    bool flag=true;
    struct voter *voters=(struct voter*)malloc(n*sizeof(struct Voter));
    while (flag == true) {
        int entry;
        printf("\nWelcome to the voter registration kiosk"
               "\nPlease enter your 8 digit Voter Registration Number");
        scanf("%d", &entry);
        if (entry==1) {
            //path for log in for PO and Admin
            printf("\nPlease select path. (1) Polling Officer (2) System Admin (3) Cancel");
            scanf("%d", &path);

            //Polling officer stuff (path1)
            if (path == 1 && po[1].officerID==1) {
                //polling officer login
                printf("\nLogin in\n---------------"
                       "\nPlease enter your first name");
                scanf("%s", &userentry);
                printf("\nPlease enter your lastname");
                scanf("%s", &userentry2);
                printf("\nPlease enter your password");
                scanf("%s", &userentry3);
                for(int l=0; l<3;l++){
                    result = strcmp(userentry, po[l].FirstName);
                    result2 = strcmp(userentry2, po[l].LastName);
                    result3 = strcmp(userentry3, po[l].Password);
                    if (result == 0 && result2==0 && result3==0){
                        printf("\n You have successfully logged in");
                        printf("\nPlease select option: (1) Register Voter (2)Declare Results (3) Cancel");
                        scanf("%d", &path);
                        if (path==1) {
                            //enter voter
                            int numOfEntries = 0;
                            numOfEntries += 1;
                            for (int j = 0; j < numOfEntries; j++) {
                                struct Voter person;
                                printf("\nPlease enter voter's First Name");
                                scanf("%s", v[j].FirstName);
                                printf("\nPlease enter voter's Last Name");
                                scanf("%s", v[j].LastName);
                                printf("\nPlease enter voter's Date of Birth (as yyyymmdd");
                                scanf("%d", &v[j].DoB);
                                v[j].RegistrationNumber = 11223344;
                            }
                        }else{
                            printf("\nInformation was incorrect");
                        }
                    }else if(path==2){
                        //END OF SESSION RESULTS OUTPUT
                        printf("\nDeclaring the results will end the session. Would you like to proceed? (1) yes (2) no");
                        scanf("%d", &path);
                        if(path==1){
                            flag=false;
                        }
                    }
                }
                //end of PO section

                //System Admin path
            } else if (path == 2) {
                if(sa[1].AdminID==1){
                    bool loginflag=false;
                    while(!loginflag) {
                        printf("\nPlease enter your username");
                        scanf("%s", &userentry);
                        result = strcmp(userentry, sa[1].LoginID);
                        if (result == 0) {
                            printf("\nPlease enter your password");
                            scanf("%s", &userentry);
                            result = strcmp(userentry, sa[1].Password);
                            if (result == 0) {
                                int POadd;
                                printf("\nYou have logged in\nPolling officer count is currently at %d."
                                       "\n Would you like to add a polling officer (1) or candidate (2)", POadd);
                                scanf("%d",&path);
                                if(path==1) {
                                    loginflag = true;
                                    //Adding polling officer - first check, if existing polling officer=3 all slots are taken
                                    POadd += 1;
                                    if (POadd == 4) {
                                        printf("\nYou have hit the limit for Polling Officers at this election.");
                                    }
                                    bool adding = false;
                                    while (!adding)
                                        for (int k = 0; k < POadd; k++) {
                                            po[1].officerID = POadd;
                                            printf("\nPlease enter the Polling officers First Name");
                                            scanf("%s", po[k].FirstName);
                                            printf("\nPlease enter the Polling officers Last Name");
                                            scanf("%s", po[k].LastName);
                                            printf("\nPlease enter the Polling officers Password");
                                            scanf("%s", po[k].Password);
                                            printf("%s %s has been added, would you like to add another polling officer? (1) yes (2) no");
                                            scanf("%d", &path);
                                            if (path == 1) {
                                            } else { adding = true; }
                                        }
                                }else if(path==2) {
                                    int candidateadd;
                                    candidateadd+=1;
                                    if(candidateadd==5){
                                        printf("You have reached the maximum number of candidates in the system.");
                                    }else{
                                    for (int p = 0; p < candidateadd; p++) {
                                        c[1].candidateID = candidateadd;
                                        printf("\nPlease enter the candidates First Name");
                                        scanf("%s", c[p].FirstName);
                                        printf("\nPlease enter the candidates Last Name");
                                        scanf("%s", c[p].LastName);
                                    }
                                    }
                                }
                            } else {
                                printf("\nPassword  incorrect, please try again");
                            }
                        } else {
                            printf("\nUserName incorrect, please try again");
                        }
                    }
                }else{
                    sa[1].AdminID=1;
                    printf("\nHello Admin, please set your username");
                    scanf("%s", sa[1].LoginID);
                    printf("\nPlease set your password");
                    scanf("%s",sa[1].Password);
                }
            }


            //Checking voter validation
        } else {


        }
    }
    return 0;
}