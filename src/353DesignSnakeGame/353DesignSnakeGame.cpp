class SnakeGame {
private:
    int width;
    int height;
    vector<vector<int>> food;
    deque<int> body;
    unordered_set<int> hist;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->width = width;
        this->height = height;
        this->food = food;
        this->body.push_back(0);
        this->hist.insert(0);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int f = body.front();
        int x = f%width;
        int y = f/width;
        if (direction=="U") {
            y -= 1;
        }else if (direction=="L"){
            x -= 1; 
        }else if (direction=="R"){
            x += 1;
        }else{
            y += 1;
        }
        f = x+y*width;
        if (x < 0 || x >= width || y < 0 || y >= height) return -1;
        int b = body.back();
        body.pop_back();
        hist.erase(b);
        
        if (hist.count(f)) return -1;
        body.push_front(f);
        hist.insert(f);
        if (food.size()>body.size()-1){
            auto q = food[body.size()-1];
            if (q[1]+q[0]*width==f) {
                body.push_back(b);
            }
        }        
        
        return this->body.size()-1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
