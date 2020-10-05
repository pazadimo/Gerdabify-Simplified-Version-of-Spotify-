using namespace std;

typedef vector<string> List;

enum UserType {Admin, Artist, Editor, Normal};

struct UserData
{
    string firstname;
    string lastname;
    string username;
    UserType userType;
};