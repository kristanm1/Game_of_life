f1 = @(x) 8.4231 + 0.000049223 * x;
figure(1);
xi_za_plot = [12500000:250000:25000000];
hold on;

v1 = [12500000, 639.5781; 15000000, 743.3706; 17500000, 856.3163; 20000000, 983.0072; 22500000, 1110.5553; 25000000, 1225.3377];
plot(v1(:, 1), v1(:, 2), 'r');

plot(xi_za_plot, f1(xi_za_plot));
plot(12500000, 639.5781, 'or');
plot(15000000, 743.3706, 'or')
plot(17500000, 856.3163, 'or')
plot(20000000, 983.0072, 'or')
plot(22500000, 1110.5553, 'or')
plot(25000000, 1225.3377, 'or')
hold off;

f2 = @(x) -30.169 + 0.000052524 * x;
figure(2);
hold on;

v2 = [12500000, 632.2506; 15000000, 756.2031; 17500000, 880.0732; 20000000, 1023.9427; 22500000, 1147.7905; 25000000, 1287.6977];
plot(v2(:, 1), v2(:, 2), 'r');

plot(xi_za_plot, f2(xi_za_plot));
plot(12500000, 632.2506, 'or');
plot(15000000, 756.2031, 'or')
plot(17500000, 880.0732, 'or')
plot(20000000, 1023.9427, 'or')
plot(22500000, 1147.7905, 'or')
plot(25000000, 1287.6977, 'or')
hold off;

f3 = @(x) -10.4764 + 0.000049685 * x;
figure(3);
hold on;

v3 = [12500000, 611.2418; 15000000, 730.1992; 17500000, 851.6333; 20000000, 976.4162; 22500000, 1094.0104; 25000000, 1237.4870];
plot(v3(:, 1), v3(:, 2), 'r');

plot(xi_za_plot, f3(xi_za_plot));
plot(12500000, 611.2418, 'or');
plot(15000000, 730.1992, 'or')
plot(17500000, 851.6333, 'or')
plot(20000000, 976.4162, 'or')
plot(22500000, 1094.0104, 'or')
plot(25000000, 1237.4870, 'or')
hold off;
