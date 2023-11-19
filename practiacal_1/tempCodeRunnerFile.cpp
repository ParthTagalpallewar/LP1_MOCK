  // string currInter;

    // if (line[0] == "START")
    // {
    //     // set counter
    //     counter = stoi(line[1]);
    //     // add to intermidiate code
    //     currInter += dp[line[0]];
    //     currInter += " {C," + line[1] + "}";

    //     intermediateCode.push_back(currInter);
    //     return;
    // }

    // // if vector is of size 2 then there must be on IS or AD and symbol
    // if (line.size() == 2)
    // {

    //     currInter += dp[line[0]];
    //     currInter += Utility::addSymbol(line[1]);
    //     intermediateCode.push_back(currInter);
    //     return;
    // }

    // // for vector of size 3 and 4
    // //  word can be
    // //  1. Symbol
    // //  2. Memo
    // //  3. Literal
    // //  4. constant

    // for (int i = 0; i < line.size(); i++)
    // {

    //     string word = line[i];

    //     // if word is memo
    //     if (dp.find(word) != dp.end())
    //     {
    //         currInter += dp[word];
    //     }

    //     else if (Utility::isConstant(word))
    //     {
    //         currInter += Utility::getConstantString(word);
    //     }

    //     else if (Utility::isSymbol(word))
    //     {

    //         if (i == 0)
    //         {
    //             currInter += Utility::addSymbol(word, counter);
    //         }
    //         else
    //         {
    //             currInter += Utility::addSymbol(word);
    //         }
    //     }
    //     else
    //     {
    //         currInter += Utility::addLiteral(word);
    //     } 
    // }
    // intermediateCode.push_back(currInter);

    // for (string row : intermediateCode)
    // {
    //     cout << row << endl;
    // }