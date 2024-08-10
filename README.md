The program is a comprehensive Blood Management System implemented in C. It manages users, donors, and blood requests using a doubly linked list structure. Below is an overview of the program:

Core Structures:
User Structure:

Stores user information such as name, username, password, email, age, and user type (admin/user).
Linked to the next and previous user nodes for managing users as a doubly linked list.
Donor Structure:

Contains donor details like name, blood type, age, email, and phone number.
Managed as a doubly linked list.
Blood Request Structure:

Manages blood requests with fields such as patient name, blood group, quantity, hospital name, city, state, contact number, ID, units required, status, and date.
Managed as a doubly linked list for adding, editing, deleting, and searching blood requests.
Key Functions:
User Management:

adduser: Adds a new user to the system.
editUser: Edits user information.
deleteUser: Deletes a user from the system.
printUserList: Displays the list of all users.
viewUserDetails: Views detailed information for a specific user.
changePassword: Allows users to change their password.
login: Handles user login and redirects based on user type (admin/user).
Donor Management:

addDonor: Adds a new donor to the system.
deleteDonor: Deletes a donor from the system.
printDonorList: Displays the list of all donors.
searchDonor: Searches for a donor by name.
Blood Request Management:

addBloodRequest: (Commented out) Adds a new blood request to the system.
deleteBloodRequest: Deletes an existing blood request.
editBloodRequest: Edits the details of a blood request.
viewBloodRequest: Views the details of a specific blood request.
printBloodRequestList: Prints the list of all blood requests.
searchBloodRequest: Searches for blood requests by patient name, blood group, or hospital name.
approveBloodRequest: Approves a pending blood request.
rejectBloodRequest: Rejects a pending blood request.
Menus:
Main Menu:

Offers options for logging in, creating an account, changing passwords, and exiting the program.
Admin Menu:

Provides a range of functionalities, including user and donor management, viewing and processing blood requests, and changing passwords.
Execution Flow:
The program begins by displaying a welcome message and offering the main menu.
Depending on the user input, it handles user creation, login, or password changes.
After login, users are directed to either the admin menu or user menu, based on their user type.
Admins have access to full system management, including adding/editing/deleting users, donors, and blood requests.
Regular users have limited access focused on viewing and managing their own requests.
This system is designed to facilitate blood donation management in a structured and organized manner, ensuring both users and admins can efficiently interact with the system.
