struct Field
{
    vector<vector<int>> table; //this will be stored done maze
    vector<Point> visited;
    vector<Point> rules = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    int maxx;
    int maxy;

    Field(int,int);
    void init_table();
    void compute();
    void drawPointBetwen(Point, Point);
    void print_table();
    vector<Point> mayNextPoints(Point);
};

Field::Field(int mx, int my):maxx(mx),maxy(my)
{
    init_table();
    compute();
}

void Field::init_table(){
    //adaption varibles
    int mx = 2 * this->maxx + 1;
    int my = 2 * this->maxy + 1;

    //filling the table
    for(int x = 0; x < mx; x++)
    {
        vector<int> temp;
        for(int y = 0; y < my ; y++)
        {
            int var = 1;
            if((x+1) % 2 == 0 && (y+1) % 2 == 0)
                var = 0;
            temp.push_back(var);
        }
        table.push_back(temp);
    }
}

void Field::compute ()
{
    Point start_p{0,0};
    Point next_p = start_p;

    int counter = 0;
    int all = maxx*maxy;
    
    while(visited.size() < all)
    {
        counter++;
       // puts(this->visited.size());
        start_p = next_p;
        //если эта точка не посещалась добавляем ее в список
        if(not presentIn(visited, start_p))
            visited.push_back(start_p);
        //ищем варианты следущей точки
        auto variants = mayNextPoints(start_p);

        if(variants.size() >= 1)
            next_p = choiceRandOf(variants);
        else 
        {
            size_t size = visited.size();
            unsigned i = size-1;
            while(mayNextPoints(start_p).size() == 0)
            {
                i--;
                //if i out of visited size range
                if(i>=size)
                    break;
                start_p = (visited[i]);
            }
            next_p = start_p;
        }
        drawPointBetwen(start_p, next_p);
    }
}

void Field::drawPointBetwen(Point a, Point b)
{
    Point temp = a + b; 
    table[temp.x + 1][temp.y + 1] = 0;
}

void Field::print_table()
{
    for(int y = 0; y < table[0].size(); y++)
    {
        for(int x = 0; x < table.size(); x++)
        {
            string out = "⬛";
            if(this->table[x][y]==0)
                out = "⬜";
            cout<<out;
        }
        cout<<endl;
    }
}

vector<Point> Field::mayNextPoints(Point point)
{
    vector<Point> result;
    for(auto rule : rules)
    {
        Point temp = point + rule;
        if(presentIn(visited, temp))
            continue;
        if(temp.inRange(maxx, maxy))
            result.push_back(temp);
    }
    return result;
}
