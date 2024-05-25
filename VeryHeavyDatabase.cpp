#include <iostream>


class VeryHeavyDatabase {

public:

     std::string GetData(const std::string& key)  {

        return "Very big data string" + key;

    }


};

class OneShotDB : public VeryHeavyDatabase {
public:
    explicit OneShotDB(VeryHeavyDatabase* real_object, size_t shots_): real_db(real_object), shots(shots_) {
       
    };

    
    std::string GetData(const std::string& key)  {

   
        if (shots != 0) {
            shots--;

            return real_db->GetData(key);
            
        }
        else return "eror";

    }
private:
    std::unique_ptr<VeryHeavyDatabase> real_db;
    size_t shots;
};

int main()
{
    auto real_db = VeryHeavyDatabase();



    auto limit_db = OneShotDB(std::addressof(real_db), 2);
    std::cout << limit_db.GetData("key") << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;
    std::cout << limit_db.GetData("key") << std::endl;

}
