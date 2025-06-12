 Q; 
    while(Q--) {
        bool found = false;
        string input; cin >> input;
        vector<int> head = color.headSearch(input), tail = name.tailSearch(input);
        for(auto h : head) {
            if (find(tail.begin(), tail.end(), h-1) != tail.end()) {
                cout << "YES" << '\n';
                found = true;
                break;
            }
        }
        if (!found) cout << "NO" << '\n';
    }