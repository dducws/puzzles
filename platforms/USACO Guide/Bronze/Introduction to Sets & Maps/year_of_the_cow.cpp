// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=1107


#include <iostream> 
#include <unordered_map>
#include <sstream>

void solve()
{
    int N;
    std::cin >> N;
    std::cin.ignore();

    // Create an unordered map to store the order of zodiac animals
    std::unordered_map<std::string, int> zodiac_animals_order;
    int count {1};
    for (const auto& animal : {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"})
        zodiac_animals_order[animal] = count++;

    // Create a map to store the birth years of cows
    std::unordered_map<std::string, std::pair<std::string, int>> birth_years {{"Bessie", {"Ox", 1}}};

    // Iterate over the input lines
    for (int i {}; i < N; ++i)
    {
        std::string line; 
        std::getline(std::cin, line);

        std::istringstream iss(line);
        std::string word;
        std::string cow1_name, order, zodiac_animal_cow1, cow2_name;
        int count {};

        // Parse the input line word by word
        while (iss >> word)
        {
            ++count;
            // Determine the position of each word and assign the values accordingly
            if (count == 1)
                cow1_name = word;
            if (count == 4)
                order = word;
            if (count == 5)
                zodiac_animal_cow1 = word; 
            cow2_name = word;
        }

        // Store the zodiac animal of cow1 in the birth_years map
        birth_years[cow1_name].first = zodiac_animal_cow1;

        // Retrieve the zodiac animal of cow2 from the birth_years map
        std::string zodiac_animal_cow2 = birth_years[cow2_name].first;
  
        // Calculate the difference in birth years based on the order specified
        if (order == "previous")
        {
            if (zodiac_animals_order[zodiac_animal_cow1] < zodiac_animals_order[zodiac_animal_cow2])
                birth_years[cow1_name].second = (- zodiac_animals_order[zodiac_animal_cow2] + zodiac_animals_order[zodiac_animal_cow1]) + birth_years[cow2_name].second;
            else 
                birth_years[cow1_name].second = - 12 + (zodiac_animals_order[zodiac_animal_cow1] - zodiac_animals_order[zodiac_animal_cow2]) + birth_years[cow2_name].second;
        }
        else if (order == "next")
        {
            if (zodiac_animals_order[zodiac_animal_cow1] > zodiac_animals_order[zodiac_animal_cow2])
                birth_years[cow1_name].second = (zodiac_animals_order[zodiac_animal_cow1] - zodiac_animals_order[zodiac_animal_cow2]) + birth_years[cow2_name].second;
            else
                birth_years[cow1_name].second = (12 - zodiac_animals_order[zodiac_animal_cow2] + zodiac_animals_order[zodiac_animal_cow1]) + birth_years[cow2_name].second;
        }
    }

    // Calculate the absolute difference in birth years between Bessie and Elsie
    std::cout << abs(birth_years["Bessie"].second - birth_years["Elsie"].second) << '\n';
}

int main()
{ 
    solve();
}
