#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct User {
	char name[50];
    char username[50];
    char password[50];
    char email[50];
    int age;
    char userType[10];
    struct User* next;
    struct User* prev;
}*head=NULL,*temp=NULL,*p=NULL;
struct Donor {
    char name[50];
    char bloodType[5];
    int age;
    char email[50];
    char phone[15];
    struct Donor* prev1;
    struct Donor* next1;
}*head1=NULL,*temp1=NULL,*p1=NULL;
struct bloodRequest {
    char patientName[50];
    char bloodGroup[5];
    int quantity;
    char hospitalName[50];
    char city[50];
    char state[50];
    char contactNo[15];
    int id; // unique identifier for the request
    int unitsRequired;
    char status[20]; // pending, approved, rejected
    char date[12];
    struct bloodRequest *next2;
    struct bloodRequest *prev2;
};
struct bloodRequest *head2 = NULL;
struct bloodRequest *tail = NULL;
void addDonor(char [], char [], int, char [], char []);
void searchByBloodGroup();
void printDonorList();
void searchDonor(char []);
void adminmenu();
void usermenu();
void deleteDonor(char []);
void adduser(char name[50],char username[50], char password[50], char email[50], int age,char userType[]);
void editUser(char name[50],char username[50], char password[50], char email[50], int age);
void deleteUser(char username[50]);
void printUserList();
void changePassword(char username[]);
void viewUserDetails(char []);
void addBloodRequest();
void deleteBloodRequest();
void editBloodRequest();
void rejectBloodRequest();
void viewBloodRequest();
void approveBloodRequest();
void count();
char a[10][10]={"A+","A-","B+","B-","AB+","AB-","O+","O-"};
void printBloodRequestList();
void searchBloodRequest();
void login();
int main(){
	printf("\n\t\t\tWelcome to the Blood Management System\n");
		int choice,age;
		char name[20],username[20],password[20],email[30],userType[10];
    do {
        	printf("\n\t\t\t\t1.Login\n\t\t\t\t2.Create an account\n\t\t\t\t3.Forgot password\n\t\t\t\t4.Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            	login();
                break;
            case 2:
            	printf("\nEnter the name :");
            	scanf("%s",name);
            	printf("\nEnter the username :");
            	scanf("%s",username);
            	printf("\nEnter the gmail :");
            	scanf("%s",email);
            	printf("\nEnter the age :");
            	scanf("%d",&age);
            	printf("\nEnter the password :");
            	scanf("%s",password);
            	printf("\nEnter the usertype :");
            	scanf("%s",userType);
                adduser(name,username,password,email,age,userType);
                break;
            case 3:
            	printf("\nEnter the username :");
            	scanf("%s",username);
            	changePassword(username);
                break;
            case 4:
            	printf("\nlogging out....\n");
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
	return 0;
}
void deleteUser(char username[50]) {
    p = head;
    while (p != NULL) {
        if (strcmp(p->username, username) == 0) {
            // Found the user, remove the node from the list
            if (p->prev == NULL) {
                // Node is at the head of the list
                head = p->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            } else if (p->next == NULL) {
                // Node is at the tail of the list
                p->prev->next = NULL;
            } else {
                // Node is in the middle of the list
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            // Free memory for the user node
            free(p);
            printf("User %s deleted\n", username);
            return;
        }
        p = p->next;
    }
    printf("User %s not found\n", username);
}
void editUser(char name[50],char username[50], char password[50], char email[50], int age) {
    p = head;
    while (p != NULL) {
        if (strcmp(p->username, username) == 0) {
            // Found the user, update the node with the new information
            strcpy(p->password, password);
            strcpy(p->email, email);
            p->age = age;
            printf("User %s edited\n", username);
            return;
        }
        p = p->next;
    }
    printf("User %s not found\n", username);
}
void printUserList() {
    p = head;
    printf("\nUSERNAME\tPASSWORD\tEMAIL\tAGE\n\n");
    while (p != NULL) {
        printf("%s\t", p->username);
        printf("%s\t", p->password);
        printf("%s\t", p->email);
        printf("%d\t", p->age);
        printf("\n\n");
        p = p->next;
    }
}
void viewUserDetails(char username[50]) {
    p = head;
    while (p != NULL) {
        if (strcmp(p->username, username) == 0) {
            // Found the user, print their information
            printf("\n\t\tThe User details for the given user\n");
            printf("Username: %s\n", p->username);
            printf("Password: %s\n", p->password);
            printf("Email: %s\n", p->email);
            printf("Age: %d\n", p->age);
            printf("\n");
            return;
        }
        p = p->next;
    }
    printf("User %s not found\n", username);
}



void deleteDonor(char name[50]) {
    struct Donor*  p1 = head1;
    while ( p1 != NULL) {
        if (strcmp( p1->name, name) == 0) {
            if ( p1 == head1) {
                head1 =  p1->next1;
                if (head1 != NULL) {
                    head1->prev1 = NULL;
                }
            } else {
                 p1->prev1->next1 = p1->next1;
                if ( p1->next1 != NULL) {
                     p1->next1->prev1 =  p1->prev1;
                }
            }
            free( p1);
            printf("Donor %s deleted\n", name);
            return;
        }
         p1 =  p1->next1;
    }
    printf("Donor %s not found\n", name);
}

// Function to print the list of donors
void printDonorList() {
    struct Donor* p1 = head1;
    printf("\nNAME\tBGP\tAGE\tEMAIL\tPHONE\n\n");
    while (p1 != NULL) {
        printf("%s\t", p1->name);
        printf("%s\t", p1->bloodType);
        printf("%d\t", p1->age);
        printf("%s\t", p1->email);
        printf("%s\t", p1->phone);
        printf("\n\n");
        p1 = p1->next1;
    }
}

// Function to search for a donor by name and print their information
void searchDonor(char name[50]) {
    struct Donor* p1 = head1;
    while (p1  != NULL) {
        if (strcmp(p1 ->name, name) == 0) {
            printf("Name: %s\n", p1 ->name);
            printf("Blood Type: %s\n", p1 ->bloodType);
            printf("Age: %d\n", p1 ->age);
            printf("Email: %s\n", p1 ->email);
            printf("Phone: %s\n", p1 ->phone);
            printf("\n");
            return;
        }
       p1  =p1 ->next1;
    }
    printf("Donor %s not found\n", name);
}
/*void addBloodRequest() {
    struct bloodRequest *newRequest = (struct bloodRequest*)malloc(sizeof(struct bloodRequest));
    printf("Enter patient name: ");
    scanf("%s", newRequest->patientName);
    printf("Enter blood group: ");
    scanf("%s", newRequest->bloodGroup);
    printf("Enter quantity: ");
    scanf("%d", &newRequest->quantity);
    printf("Enter hospital name: ");
    scanf("%s", newRequest->hospitalName);
    printf("Enter city: ");
    scanf("%s", newRequest->city);
    printf("Enter state: ");
    scanf("%s", newRequest->state);
    printf("Enter contact number: ");
    scanf("%s", newRequest->contactNo);
    printf("Enter unique identifier: ");
    scanf("%d", &newRequest->id);
    strcpy(newRequest->status, "pending");
    newRequest->next2 = NULL;
    newRequest->prev2 = NULL;
    if (head2 == NULL) {
        head2 = newRequest;
        tail = newRequest;
    } else {
        tail->next2 = newRequest;
        newRequest->prev2 = tail;
        tail = newRequest;
    }
    printf("Blood request added successfully.\n");
}*/

// Function to delete an existing blood request from the list
void deleteBloodRequest() {
    int id;
    printf("Enter unique identifier of the blood request to delete: ");
    scanf("%d", &id);
    struct bloodRequest *current = head2;
    while (current != NULL) {
        if (current->id == id) {
            if (current == head2 && current == tail) {
                head2 = NULL;
                tail = NULL;
            } else if (current == head2) {
                head2 = current->next2;
                head2->prev2 = NULL;
            } else if (current == tail) {
                tail = current->prev2;
                tail->next2 = NULL;
            } else {
                current->prev2->next2 = current->next2;
                current->next2->prev2 = current->prev2;
            }
            free(current);
            printf("Blood request deleted successfully.\n");
            return;
        }
        current = current->next2;
    }
    printf("Blood request with unique identifier %d not found.\n", id);
}
void editBloodRequest() {
    int id;
    printf("Enter unique identifier of the blood request to edit: ");
    scanf("%d", &id);
    struct bloodRequest *current = head2;
    while (current != NULL) {
        if (current->id == id) {
            printf("Enter patient name (old: %s): ", current->patientName);
            scanf("%s", current->patientName);
            printf("Enter blood group (old: %s): ", current->bloodGroup);
            scanf("%s", current->bloodGroup);
            printf("Enter hospital name (old: %s): ", current->hospitalName);
            scanf("%s", current->hospitalName);
            printf("Enter number of units required (old: %d): ", current->unitsRequired);
            scanf("%d", &current->unitsRequired);
            printf("Enter date of blood request (old: %s): ", current->date);
            scanf("%s", current->date);
            printf("Blood request details updated successfully.\n");
            return;
        }
        current = current->next2;
    }
    printf("Blood request with ID %d not found.\n", id);
}
void viewBloodRequest() {
    int id;
    printf("Enter unique identifier of the blood request to view: ");
    scanf("%d", &id);
    struct bloodRequest *current = head2;
    while (current != NULL) {
        if (current->id == id) {
            printf("Blood request details:\n");
            printf("ID: %d\n", current->id);
            printf("Patient name: %s\n", current->patientName);
            printf("Blood group: %s\n", current->bloodGroup);
            printf("Hospital name: %s\n", current->hospitalName);
            printf("Units required: %d\n", current->unitsRequired);
            printf("Date of request: %s\n", current->date);
            printf("Status: %s\n", current->status);
            return;
        }
        current = current->next2;
    }
    printf("Blood request with ID %d not found.\n", id);
}
void printBloodRequestList() {
    struct bloodRequest *current = head2;
    printf("List of all blood requests:\n");
    while (current != NULL) {
        printf("ID: %d\n", current->id);
        printf("Patient name: %s\n", current->patientName);
        printf("Blood group: %s\n", current->bloodGroup);
        printf("Hospital name: %s\n", current->hospitalName);
        printf("Units required: %d\n", current->unitsRequired);
        printf("Date of request: %s\n", current->date);
        printf("Status: %s\n\n", current->status);
        current = current->next2;
    }
}
void searchBloodRequest() {
    int choice;
    printf("Search by:\n");
    printf("1. Patient name\n");
    printf("2. Blood group\n");
    printf("3. Hospital name\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    struct bloodRequest *current = head2;
    int count = 0;
    switch (choice) {
        case 1:
            char patientName[50];
            printf("Enter patient name: ");
            scanf("%s", patientName);
            while (current != NULL) {
                if (strcmp(current->patientName, patientName) == 0) {
                    printf("Blood request details:\n");
                    printf("ID: %d\n", current->id);
                    printf("Blood group: %s\n", current->bloodGroup);
                    printf("Hospital name: %s\n", current->hospitalName);
                    printf("Units required: %d\n", current->unitsRequired);
                    printf("Date of request: %s\n", current->date);
                    printf("Status: %s\n", current->status);
                    count++;
                }
                current = current->next2;
            }
            if (count == 0) {
                printf("No blood requests found for patient %s.\n", patientName);
            }
            break;

        case 2:
            char bloodGroup[5];
            printf("Enter blood group: ");
            scanf("%s", bloodGroup);
            while (current != NULL) {
                if (strcmp(current->bloodGroup, bloodGroup) == 0) {
                    printf("Blood request details:\n");
                    printf("ID: %d\n", current->id);
                    printf("Patient name: %s\n", current->patientName);
                    printf("Hospital name: %s\n", current->hospitalName);
                    printf("Units required: %d\n", current->unitsRequired);
                    printf("Date of request: %s\n", current->date);
                    printf("Status: %s\n", current->status);
                    count++;
                }
                current = current->next2;
            }
            if (count == 0) {
                printf("No blood requests found for blood group %s.\n", bloodGroup);
            }
            break;

        case 3:
            char hospitalName[50];
            printf("Enter hospital name: ");
            scanf("%s", hospitalName);
            while (current != NULL) {
                if (strcmp(current->hospitalName, hospitalName) == 0) {
                    printf("Blood request details:\n");
                    printf("ID: %d\n", current->id);
                    printf("Patient name: %s\n", current->patientName);
                    printf("Blood group: %s\n", current->bloodGroup);
                    printf("Units required: %d\n", current->unitsRequired);
                    printf("Date of request: %s\n", current->date);
                    printf("Status: %s\n", current->status);
                    count++;
                }
                current = current->next2;
            }
            if (count == 0) {
                printf("No blood requests found for hospital %s.\n", hospitalName);
            }
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }
}
void approveBloodRequest() {
    int id;
    printf("Enter unique identifier of the blood request to approve: ");
    scanf("%d", &id);
    struct bloodRequest *current = head2;
    while (current != NULL) {
        if (current->id == id) {
            if (current->status == "PENDING") {
                strcpy(current->status,"APPROVED");
                printf("Blood request with ID %d has been approved.\n", id);
            } else {
                printf("Blood request with ID %d has already been processed.\n", id);
            }
            return;
        }
        current = current->next2;
    }
    printf("Blood request with ID %d not found.\n", id);
}
void rejectBloodRequest() {
    int id;
    printf("Enter unique identifier of the blood request to reject: ");
    scanf("%d", &id);
    struct bloodRequest *current = head2;
    while (current != NULL) {
        if (current->id == id) {
            if (current->status == "PENDING") {
                strcpy(current->status,"REJECTED");
                printf("Blood request with ID %d has been rejected.\n", id);
            } else {
                printf("Blood request with ID %d has already been processed.\n", id);
            }
            return;
        }
        current = current->next2;
    }
    printf("Blood request with ID %d not found.\n", id);
}
void changePassword(char username[]) {
    char currentPassword[10];
    char newPassword[10];
    printf("Enter your current password: ");
    scanf("%s", currentPassword);
    printf("Enter your new password: ");
    scanf("%s", newPassword);
	while(p!=NULL){
		if(strcmp(currentPassword,p->password)==0){
			 strcpy(p->password, newPassword);
   			 printf("Password changed successfully.\n");
   			 return;
		}
		p=p->next;
	}
    printf("Incorrect password.\n");
}
void login() {
    char username[50];
    char password[50];

    // Prompt the user to enter their username and password
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    // Find the user in the user list
    struct User* p = head;
    while (p != NULL) {
        if (strcmp(p->username, username) == 0 && strcmp(p->password, password) == 0) {
            printf("Login successful!\n");
            if (strcmp(p->userType, "admin") == 0) {
                // User is an admin
                printf("\t\t\tWelcome, admin %s!\n", p->name);
                adminmenu();
            } else {
                // User is a regular user
                printf("\t\t\tWelcome, %s!\n", p->name);
                usermenu();
            }
            return;
        }
        p = p->next;
    }

    // User not found or password incorrect
    printf("Invalid username or password.\n");
}
void adminmenu(){
	int choice,age;
	char name[20],username[20],password[20],email[30],userType[10];
	//char name[50];
    char bloodType[5];
  //  int age;
    //char email[50];
    char phone[15];
    do {
        printf("\n\n\t\t\t--- Admin Menu ---\n");
        printf("\t\t\t\t1. Add User\n");
        printf("\t\t\t\t2. Delete User\n");
        printf("\t\t\t\t3. Edit User\n");
        printf("\t\t\t\t4. View User List\n");
        printf("\t\t\t\t5. UserDetails\n");
        printf("\t\t\t\t6. Adddonor\n");
        printf("\t\t\t\t7. Searchdonor\n");
        printf("\t\t\t\t8. printDonorList\n");
        printf("\t\t\t\t9. View Blood Request List\n");
        printf("\t\t\t\t10. Search Blood Request\n");
        printf("\t\t\t\t11. Approve Blood Request\n");
        printf("\t\t\t\t12. Reject Blood Request\n");
        printf("\t\t\t\t13. Change Password\n");
        printf("\t\t\t\t14. Logout\n");
        printf("Enter your choice (1-14): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the name :");
            	scanf("%s",name);
            	printf("\nEnter the username :");
            	scanf("%s",username);
            	printf("\nEnter the gmail :");
            	scanf("%s",email);
            	printf("\nEnter the age :");
            	scanf("%d",&age);
            	printf("\nEnter the password :");
            	scanf("%s",password);
            	printf("\nEnter the usertype :");
            	scanf("%s",userType);
                adduser(name,username,password,email,age,userType);
                break;
            case 2:
            	printf("\nEnter the username :");
            	scanf("%s",username);
                deleteUser(username);
                break;
            case 3:
            	printf("\nEnter the name :");
            	scanf("%s",name);
            	printf("\nEnter the username :");
            	scanf("%s",username);
            	printf("\nEnter the gmail :");
            	scanf("%s",email);
            	printf("\nEnter the age :");
            	scanf("%d",&age);
            	printf("\nEnter the password :");
            	scanf("%s",password);
                editUser(name,username,password,email,age);
                break;
            case 4:
                printUserList();
                break;
            case 5:
            	printf("\nEnter the username :");
            	scanf("%s",username);
                viewUserDetails(username);
                break;
            case 6:
            	printf("\nEnter the name :");
            	scanf("%s",name);
            	printf("\nEnter the bloodtype :");
            	scanf("%s",bloodType);
            	printf("\nEnter the age :");
            	scanf("%d",&age);
            	printf("\nEnter the email :");
            	scanf("%s",email);
            	printf("\nEnter the phoneno :");
            	scanf("%s",phone);
            	addDonor(name,bloodType,age,email,phone);
            	break;
            case 7:
            	printf("\nEnter the name of the donor\n");
            	scanf("%s",name);
                searchDonor(name);
                break;
            case 8:
                printDonorList();
                break;
            case 9:
                printBloodRequestList();
                break;
            case 10:
                searchBloodRequest();
                break;
            case 11:
                approveBloodRequest();
                break;
            case 12:
                rejectBloodRequest();
                break;
            case 13:
                printf("\nEnter the username :");
            	scanf("%s",username);
            	changePassword(username);
                break;
            case 14:
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 14);
}
void usermenu(){
	int choice;
	char username[20];
    do {
        printf("\n\n\t\t\t--- User Menu ---\n");
        printf("\t\t\t\t1. Blood Request\n");
        printf("\t\t\t\t2. View donor list\n");
        printf("\t\t\t\t3. Donors count in each blood group\n");
        printf("\t\t\t\t4. Searchby Bloodgroup\n");
        printf("\t\t\t\t5. Change Password\n");
        printf("\t\t\t\t6. Logout\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
            	printf("\n1.Add Request\n2.Delete Request\n3.Edit Request\n4.View Request\n5.Search Request\n");
                printf("Enter your choice (1-4): ");
        		scanf("%d", &choice);
        		switch (choice) {
           			 case 1:
                		addBloodRequest();
              		  break;
            		case 2:
               			 deleteBloodRequest();
               		 break;
            		case 3:
            			editBloodRequest();
               		 break;
            		case 4:
             		   	viewBloodRequest();
              		  break;
              		case 5:
              			searchBloodRequest();
              		break;
            		default:
               			 printf("Invalid choice. Please try again.\n");
               		 break;
        }
                break;
            case 2:
                printDonorList();
                break;
            case 3:
            	printf("\nNumber of donors belongs to particular blood group");
            	count();
            	break;
            case 4:
				searchByBloodGroup();
            	break;
            case 5:
            	printf("\nEnter the username :\n");
            	scanf("%s",username);
                changePassword(username);
                break;
            case 6:
                printf("Logging out...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);
}
void count(){
	int i,c[8]={0,0,0,0,0,0,0,0};
		if(head1==NULL){
        printf("Empty list");
        return;
    }
    p1=head1;
    while(p1!=NULL){
		for(i=0;i<8;i++){
			if(strcmp(p1->bloodType,a[i])==0){
				c[i]=c[i]+1;
			}
		}
        p1=p1->next1;
    }
    printf("\nThe available blood packets   :\n");
    for(i=0;i<8;i++)
    	printf("\n%s      ------>      %d\n",a[i],c[i]);
}
void searchByBloodGroup() {
    char bloodGroup[4];
    printf("Enter blood group to search for: ");
    scanf("%s", bloodGroup);
    
    p1 = head1;
    int found = 0;
    while (p1 != NULL) {
        if (strcmp(p1->bloodType, bloodGroup) == 0) {
            found = 1;
             printf("Name: %s\n", p1 ->name);
            printf("Blood Type: %s\n", p1 ->bloodType);
            printf("Age: %d\n", p1 ->age);
            printf("Email: %s\n", p1 ->email);
            printf("Phone: %s\n", p1 ->phone);
            printf("--------------------\n");
        }
        p1 = p1->next1;
    }
    if (!found) {
        printf("No donors with blood group %s found.\n", bloodGroup);
    }
}
void writeToFile(struct User *node) {
    // Open the file in append mode
    FILE *fp = fopen("users.txt", "a");

    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Write the user data to the file
    fwrite(node, sizeof(struct User), 1, fp);

    // Add a newline character after writing the structure
    fprintf(fp, "\n");

    // Close the file
    fclose(fp);
}


void adduser(char name[50],char username[50], char password[50], char email[50], int age,char userType[]){
    // Create a new user node
    struct User *temp = (struct User*)malloc(sizeof(struct User));
    strcpy(temp->name,name);
    strcpy(temp->username,username);
    strcpy(temp->password,password);
    strcpy(temp->email,email);
    strcpy(temp->userType,userType);
    temp->age = age;
    temp->next = NULL;
    temp->prev = NULL;

    // Insert the user node at the head of the linked list
    if (head == NULL) {
         head = temp;
    } else {
        head->prev = temp;
        temp->next = head;
        head = temp;
    }
	printf("\n\nThankyou for signing up........\n\n");
    // Write the user data to the file
    writeToFile(temp);
}
void writeDonorToFile(struct Donor *node) {
    FILE *fp = fopen("donors.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fwrite(node, sizeof(struct Donor), 1, fp);
    fprintf(fp, "\n"); // Add a newline character after writing the structure

    fclose(fp);
}
void addDonor(char name[50], char bloodType[5], int age, char email[50], char phone[15]) {
    struct Donor* temp1 = (struct Donor*) malloc(sizeof(struct Donor));
    strcpy(temp1->name, name);
    strcpy(temp1->bloodType, bloodType);
    temp1->age = age;
    strcpy(temp1->email, email);
    strcpy(temp1->phone, phone);
    temp1->prev1 = NULL;
    temp1->next1 = NULL;

    if (head1 == NULL) {
        head1 = temp1;
    } else {
        p1 = head1;
        while (p1->next1 != NULL) {
            p1 = p1->next1;
        }
        p1->next1 = temp1;
        temp1->prev1 = p1;
    }

    // Write the donor data to the file
    writeDonorToFile(temp1);
}
void writeRequestToFile(struct bloodRequest *request) {
    FILE *fp = fopen("blood_requests.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fwrite(request, sizeof(struct bloodRequest), 1, fp);
    fprintf(fp, "\n"); // Add a newline character after writing the structure

    fclose(fp);
}

void addBloodRequest() {
    struct bloodRequest *newRequest = (struct bloodRequest*)malloc(sizeof(struct bloodRequest));
    printf("Enter patient name: ");
    scanf("%s", newRequest->patientName);
    printf("Enter blood group: ");
    scanf("%s", newRequest->bloodGroup);
    printf("Enter quantity: ");
    scanf("%d", &newRequest->quantity);
    printf("Enter hospital name: ");
    scanf("%s", newRequest->hospitalName);
    printf("Enter city: ");
    scanf("%s", newRequest->city);
    printf("Enter state: ");
    scanf("%s", newRequest->state);
    printf("Enter contact number: ");
    scanf("%s", newRequest->contactNo);
    printf("Enter unique identifier: ");
    scanf("%d", &newRequest->id);
    strcpy(newRequest->status, "pending");
    newRequest->next2 = NULL;
    newRequest->prev2 = NULL;

    if (head2 == NULL) {
        head2 = newRequest;
        tail = newRequest;
    } else {
        tail->next2 = newRequest;
        newRequest->prev2 = tail;
        tail = newRequest;
    }

    // Write the blood request to the file
    writeRequestToFile(newRequest);

    printf("Blood request added successfully.\n");
}



