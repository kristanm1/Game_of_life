
f1 = @(x) 2.2983e-01 + 1.1871e-04 .* x;
f2 = @(x) -1.4193e+02 + 7.7893e-05 .* x;
f3 = @(x) 2.0025e+02 + 6.4190e-05 .* x;
figure(1);
xi_za_plot = 20000000:1000:50000000;

%na eni niti
hold on;
plot(xi_za_plot, f1(xi_za_plot), 'r');
plot(20000000, 2378.7289, 'ob');
plot(30000000, 3558.1211, 'ob')
plot(40000000, 4741.9400, 'ob')
plot(50000000, 5940.9955, 'ob')
hold off;

%na vec nitih, vsako generacijo nove niti + unicimo niti
figure(2);
hold on;
plot(xi_za_plot, f2(xi_za_plot), 'r');
plot(20000000, 1453.5480, 'ob');
plot(30000000, 2180.8337, 'ob')
plot(40000000, 2888.9453, 'ob')
plot(50000000, 3813.9365, 'ob')
hold off;

%za n generacij naredimo 1x k niti
figure(3);
hold on;
plot(xi_za_plot, f3(xi_za_plot), 'r');
plot(20000000, 1455.5712, 'ob');
plot(30000000, 2157.2261, 'ob')
plot(40000000, 2790.8168, 'ob')
plot(50000000, 3384.0529, 'ob')
hold off;


