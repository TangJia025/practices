static int collinearPointsCount(vector<Point> A)
{
	if (A.size() == 0)
	    return 0;
	int ret = 0;
	int n = A.size();
    map<float, vector<pair<Point, Point> > > slope;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			float k = (A[i].y - A[j].y) / (A[i].x - A[j].x);
			slope[k].push_back(make_pair(A[i], A[j]));
		}
	}
    map<float, vector<pair<Point, Point> >::iterator iter = slope.begin();
	for (; iter != slope.end(); iter++)
	{
		vector<pair<Point, Point> > B = iter->second;
		







