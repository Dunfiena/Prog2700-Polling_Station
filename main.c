#include <stdio.h>
#include <stdbool.h>
#include <String.h>

struct Voter{
    char FirstName[50];
    char LastName[50];
    int RegistrationNumber;
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
    int path, result, result2, result3, numofVoters=0, numofentries=0;
    int POadd=0, p=0, j=0, k=0;
    int candidateadd=0;
    bool startflag=true;

    bool flag=true;
    while (flag == true) {
        int entry;
        printf("\nWelcome to the voter registration kiosk"
               "\nPlease enter your 8 digit Voter Registration Number");

        scanf("%d", &entry);
        if (entry == 1) {
            //path for log in for PO and Admin
            printf("\nPlease select path. (1) Polling Officer (2) System Admin (3) Cancel");
            scanf("%d", &path);

            //Polling officer stuff (path1)
            if (path == 1 && po[0].officerID == 1) {
                //polling officer login
                printf("\nLogin in\n---------------"
                       "\nPlease enter your first name");
                scanf("%s", userentry);
                printf("\nPlease enter your lastname");
                scanf("%s", userentry2);
                printf("\nPlease enter your password");
                scanf("%s", userentry3);
                for (int l = 0; l < 3; l++) {
                    result = strcmp(userentry, po[l].FirstName);
                    result2 = strcmp(userentry2, po[l].LastName);
                    result3 = strcmp(userentry3, po[l].Password);
                    if (result == 0 && result2 == 0 && result3 == 0) {
                        printf("\n You have successfully logged in");
                        bool poSession = true;
                        while (poSession) {
                            printf("\nPlease select option: (1) Register Voter (2) Add Candidate (3)Declare Results (4) Fix voter issue (5) Cancel");
                            scanf("%d", &path);
                            if (path == 1) {
                                //enter voter
                                numofentries += 1;
                                for (j; j < numofentries; j++) {
                                    printf("\nPlease enter voter's First Name");
                                    scanf("%s", v[j].FirstName);
                                    printf("\nPlease enter voter's Last Name");
                                    scanf("%s", v[j].LastName);
                                    printf("\nPlease enter voter's Date of Birth (as yyyymmdd)");
                                    scanf("%d", &v[j].DoB);
                                    printf("\nPlease enter voter's 8 digit registration number");
                                    scanf("%d", &v[j].RegistrationNumber);
                                    v[j].hasVoted=false;
                                    numofVoters += 1;
                                }
                            } else if (path == 2) {
                                candidateadd += 1;
                                if (candidateadd == 6) {
                                    printf("You have reached the maximum number of candidates in the system.");
                                } else {
                                    for (p; p < candidateadd; p++) {
                                        c[p].candidateID = p+1;
                                        printf("\nPlease enter the candidates First Name");
                                        scanf("%s", c[p].FirstName);
                                        printf("\nPlease enter the candidates Last Name");
                                        scanf("%s", c[p].LastName);
                                    }
                                }
                            } else if (path == 3) {
                                //END OF SESSION RESULTS OUTPUT
                                printf("\nDeclaring the results will end the session. Would you like to proceed? (1) yes (2) no");
                                scanf("%d", &path);
                                if (path == 1) {
                                    flag = false;
                                    poSession = false;
                                    int mostvotes = 0;
                                    int times = 0;
                                    int winner;
                                    for (int q = 0; q <= 4; q++) {
                                        if (c[q].candidateID == q+1) {
                                            printf("\n%s %s has a total of %d votes", c[q].FirstName, c[q].LastName,
                                                   c[q].Votes);
                                            times += 1;
                                            int votes = c[q].Votes;
                                            if (votes > mostvotes) {
                                                mostvotes = votes;
                                                winner = q;
                                            }
                                        } else {
                                            printf("\nThe results of this election are as follows"
                                                   "\n------------------------------------------"
                                                   "\nWinner of the election is %s %s with %d votes",
                                                   c[winner].FirstName,
                                                   c[winner].LastName, c[winner].Votes);
                                            printf("\nEnd of Session, thank you for your service.");
                                            l = 4;
                                            break;
                                        }
                                    }
                                }
                            }else if(path==4){
                                printf("\nPlease enter the registration number for the voter");
                                scanf("%d", &path);
                                for(int y=0;y<numofVoters;y++){
                                    if(path==v[y].RegistrationNumber){
                                        printf("\nPlease enter voter's First Name");
                                        scanf("%s", v[y].FirstName);
                                        printf("\nPlease enter voter's Last Name");
                                        scanf("%s", v[y].LastName);
                                        printf("\nPlease enter voter's Date of Birth (as yyyymmdd)");
                                        scanf("%d", &v[y].DoB);
                                        v[j].hasVoted=false;
                                    }else if(y==numofVoters-1){
                                        printf("There is no voter with that registration number.  Please add them from menu by pressing (1)");
                                    }else{

                                    }
                                }

                            }else {
                                poSession = false;
                                l = 4;
                                break;
                            }
                        }
                    } else {
                        if (l < 2) {
                        } else {
                        printf("\nInformation was incorrect");
                    }
                }
                }
                //end of PO section

                //System Admin path
            } else if (path == 2) {
                while (startflag) {
                    sa[0].AdminID = 1;
                    printf("\nHello Admin, please set your username");
                    scanf("%s", sa[0].LoginID);
                    printf("\nPlease set your password");
                    scanf("%s", sa[0].Password);
                    startflag = false;
                }
                    bool loginflag = false;
                    while (!loginflag) {
                        printf("\nPlease enter your username");
                        scanf("%s", userentry);
                        result = strcmp(userentry, sa[0].LoginID);
                        if (result == 0) {
                            printf("\nPlease enter your password");
                            scanf("%s", userentry);
                            result = strcmp(userentry, sa[0].Password);
                            if (result == 0) {
                                loginflag = true;
                                printf("\nYou have logged in\nPolling officer count is currently at %d."
                                       "\n Would you like to add a polling officer (1) or cancel (2)", POadd);
                                scanf("%d", &path);
                                if (path == 1) {
                                    //Adding polling officer - first check, if existing polling officer=3 all slots are taken
                                    if (POadd == 3) {
                                        printf("\nYou have hit the limit for Polling Officers at this election.");
                                    }else{
                                        POadd += 1;
                                        bool adding = true;
                                    while (adding) {
                                        for (k; k < POadd; k++) {
                                            po[k].officerID = POadd;
                                            printf("\nPlease enter the Polling officers First Name");
                                            scanf("%s", po[k].FirstName);
                                            printf("\nPlease enter the Polling officers Last Name");
                                            scanf("%s", po[k].LastName);
                                            printf("\nPlease enter the Polling officers Password");
                                            scanf("%s", po[k].Password);
                                            printf("%s %s has been added, would you like to add another polling officer? (1) yes (2) no",
                                                   po[k].FirstName, po[k].LastName);
                                            scanf("%d", &path);
                                            if (path == 1 && POadd <3) {
                                                printf("Adding another polling officer");
                                                POadd += 1;
                                            } else if(path==1 && POadd==3){
                                                printf("\nYou have hit the limit for Polling Officers at this election.");
                                                adding = false;
                                            }else{
                                                adding = false; }
                                        }
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
                }
            //END OF SYSADMIN SECTION

            //Checking voter validation
            } else {
            for (int i = 0; i < numofVoters; i++) {
                if(entry==v[i].RegistrationNumber && v[i].hasVoted==false){
                    printf("\nPlease confirm that %d is your date of birth (1) yes (2) no", v[i].DoB);
                    scanf("%d", &path);
                    if(path==1){
                        if(v[i].DoB<20050316){
                            printf("\nPlease cast your vote");
                            for(int j=0;j<candidateadd;j++) {
                                printf("\n%d - %s %s )", j+1, c[j].FirstName, c[j].LastName);
                            }
                            scanf("%d",&path);
                            c[path-1].Votes+=1;
                            v[i].hasVoted=true;
                            break;
                            }else{
                            printf("\nThere has been a mistake as your age is incorrect."
                                   "Please see polling officer to confirm your date of birth.");
                        }
                        }else{
                        printf("\nThere has been a mistake as your age is incorrect."
                               "Please see polling officer to confirm your date of birth.");
                                break;
                    }
                    }else if(entry==v[i].RegistrationNumber && v[i].hasVoted==true) {
                    printf("\nA vote has already been cast by this user."
                           "If you have not cast a vote, please see the polling officer");
                }else {
                    if (i < numofVoters-1) {
                    } else {
                        printf("\nThis registration number doesn't exist in the system."
                               "Please see the polling officer to correct this.");
                    }
                }
                }
            }
        }
    return 0;
}