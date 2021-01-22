#include<iostream.h>
#include<math.h>
#include<stdlib.h>
double gaussian_box_muller()                //creating gaussian box muller function
{
      double x=0.0;
      double y=0.0;
      double euclid_sq=0.0;
      do
      {
	 x=((double) rand()/(RAND_MAX))*2.0-1.0;
	 y=((double) rand()/(RAND_MAX))*2.0-1.0;
	 euclid_sq=(x*x)+(y*y);
      }
      while(euclid_sq>=1);
	 return x*sqrt(-2*log(euclid_sq)/euclid_sq);
}
double monte_carlo_call_price(const int& num_sims, const double& s, const double& k, const double& r, const double& v, const double& t)   //creating monte carlo call price function
{
      double s_adjust=s*exp(t*(r-0.5*v*v));
      double s_cur=0.0;
      double payoff_sum=0.0;
      for(int i=0; i<num_sims; i++)
      {
	   double gauss_bm=gaussian_box_muller();
	   s_cur=s_adjust*exp(sqrt(v*v*t)*gauss_bm);
	   if(s_cur>k)
	       payoff_sum=payoff_sum+(s_cur-k);
	   else
	       payoff_sum=payoff_sum;
      }
      return (payoff_sum/(double)(num_sims))*exp(-r*t);
}
int main()
{
     int num_sims=10000;
     double s=50.0;
     double k=50.0;
     double r=0.05;
     double v=0.3;
     double t=1;
     double call=monte_carlo_call_price(num_sims,s,k,r,v,t);
     cout<<"Number of steps: "<<num_sims<<endl;
     cout<<"Underlying: "<<s<<endl;
     cout<<"Strike price: "<<k<<endl;
     cout<<"Riskfree rate: "<<r<<endl;
     cout<<"Volatility: "<<v<<endl;
     cout<<"Maturity:  "<<t<<endl;
     cout<<"Call Price:  "<<call<<endl;
     return 0;
}
