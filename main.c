#include<unistd.h>
#include<stdio.h>

int main()
{
	int		i;
	int		j;
	int		temp;
    int     num;
    double  dist[10] = {7.6, 3.5, 2.4, 9.8, 7.6, 8.5, 5.3, 4.2, 1.1};
    int     ord[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	i = 0;
	j = 0;
    num = 10;
	while (i < num)
	{
		printf("%f\n", dist[ord[i]]);
		i++;
	}
    printf("\n");
	i = 0;
	while (i < num)
	{
		j = i + 1;
		while (j < num)
		{
			if (dist[i] < dist[j])
			{
				temp = ord[i];
				ord[i] = ord[j];
				ord[j] = temp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < num)
	{
		printf("%f\n", dist[ord[i]]);
		i++;
	}
    return (0);
}