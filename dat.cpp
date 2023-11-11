#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Profile {
    string name;
    int age;
    string location;
    string interests;
    string qualification;
};

class DatingApp {
public:
    DatingApp() {}

    void addUserProfile() {
        Profile user;
        cout << "Enter your name: ";
        getline(std::cin, user.name);
        cout << "Enter your age: ";
        cin >> user.age;
        cin.ignore();
        cout << "Enter your location: ";
        getline(cin, user.location);
        cout << "Enter your interests: ";
        getline(cin, user.interests);
        userProfiles.push_back(user);
        getline(cin, user.qualification);
        cin.ignore();
    }

    void addCandidateProfile() {
        Profile candidate;
        cout << "Enter candidate's name: ";
        getline(cin, candidate.name);
        cout << "Enter candidate's age: ";
        cin >> candidate.age;
        cin.ignore(); 
        cout << "Enter candidate's location: ";
        getline(cin, candidate.location);
        cout << "Enter candidate's interests: ";
        getline(cin, candidate.interests);
        cout <<"Enter candidate's Qualification: ";
        getline(cin, candidate.qualification);
        candidateProfiles.push_back(candidate);
    }

    void findMatches(const Profile& user) {
    for (const Profile& candidate : candidateProfiles) {
        float compatibility = calculateCompatibility(user, candidate);
        if (compatibility >= 0.5) {
            cout << "Match: " << user.name << " and " << candidate.name << " with compatibility " << compatibility << std::endl;
            cout << std::flush; 
        }
    }
}



    vector<Profile> userProfiles;
    vector<Profile> candidateProfiles;

    float calculateCompatibility(const Profile& user, const Profile& candidate) {
        float compatibility = 0;
        if (user.age == candidate.age) {
            compatibility += 0.2;
        }
        if (user.location == candidate.location) {
            compatibility += 0.2;
        }

        
        if (user.interests == candidate.interests) {
            compatibility += 0.1;
        }
        if(user.qualification == candidate.qualification){
            compatibility += 0.2;
        }

        return compatibility;
    }
};

int main() {
    DatingApp datingApp;

    int numCandidates;

    cout << "Enter the number of candidates you want to add: ";
    cin >> numCandidates;
    cin.ignore(); 

    for (int i = 0; i < numCandidates; ++i) {
        datingApp.addCandidateProfile();
    }

    datingApp.addUserProfile();

    cout << "Finding matches for the user:\n";
    const Profile& user = datingApp.userProfiles.back();
    datingApp.findMatches(user);

    cout << "Press Enter to exit...";
    cin.get();


    return 0;
}
