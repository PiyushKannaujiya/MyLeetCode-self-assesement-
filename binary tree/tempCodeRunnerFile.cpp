 // already thread exit
        else {
            pred ->right = NULL;
            cout << curr ->data << " ";
            curr = curr ->right;
        }