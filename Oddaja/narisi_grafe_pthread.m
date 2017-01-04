x = [1000000, 2000000, 4000000, 8000000]';
t = linspace(200000, 8800000, 1000);

%---v:100, s:100, st_iteracij:(100, 200, 400, 800) :: 1 NIT---
figure(1);
hold on;
y = [122.7887, 239.1517, 474.4584, 948.4117]';
f = @(x) 3.6139 + 1.1802e-04 * x;
plot(x, y, 'ro');
plot(t, f(t), 'r');

%---v:100, s:100, st_iteracij:(100, 200, 400, 800) :: 2 NIT---OMP
y = [67.5268, 133.1581, 267.1018, 529.9299]';
f = @(x) 1.5702e+00 + 6.6096e-05 * x;
plot(x, y, 'bo');
plot(t, f(t), 'b');

%---v:100, s:100, st_iteracij:(100, 200, 400, 800) :: 2 NIT---multy2
y = [70.6313, 147.5765, 278.0182, 588.3889]';
f = @(x) -5.0631e+00 + 7.3658e-05 * x;
plot(x, y, 'go');
plot(t, f(t), 'g');

%---v:100, s:100, st_iteracij:(100, 200, 400, 800) :: ---OCL
y = [11.0602, 22.0049, 44.0362, 99.6850]';
f = @(x) -3.5094e+00 + 1.2722e-05 * x;
plot(x, y, 'ko');
plot(t, f(t), 'k');


ylabel('Cas[ms]');
xlabel('N');

hold off;

%-------------------------------------------------------------------------------

%---v:100, s:(100, 200, 400, 800), st_iteracij:100 :: 1 NIT---
figure(2);
hold on;
y = [122.3245, 238.6107, 476.8630, 956.5746]';
f = @(x) 1.1110e+00 + 1.1933e-04 * x;
plot(x, y, 'ro');
plot(t, f(t), 'r');

%---v:100, s:(100, 200, 400, 800), st_iteracij:100 :: 2 NIT---OMP
figure(2);
hold on;
y = [66.8121, 132.4837, 263.2500, 526.2111]';
f = @(x) 1.1071e+00 + 6.5622e-05 * x;
plot(x, y, 'bo');
plot(t, f(t), 'b');

%---v:100, s:(100, 200, 400, 800), st_iteracij:100 :: 2 NIT---multy2
y = [72.3517, 135.0592, 270.5487, 610.8969]';
f = @(x) -1.8477e+01 + 7.7518e-05 * x;
plot(x, y, 'go');
plot(t, f(t), 'g');

%---v:100, s:100, st_iteracij:(100, 200, 400, 800) :: ---OCL
y = [11.0679, 17.1028, 29.5033, 56.9540]';
f = @(x) 3.9965e+00 + 6.5761e-06 * x;
plot(x, y, 'ko');
plot(t, f(t), 'k');

ylabel('Cas[ms]');
xlabel('N');

hold off;

%-------------------------------------------------------------------------------

figure(3);
%---v:(100, 200, 400, 800), s:100, st_iteracij:100 :: 1 NIT---
hold on;
y = [121.3116, 239.5597, 477.5898, 956.0098]';
f = @(x) 1.2782e+00 + 1.1929e-04 * x;
plot(x, y, 'ro');
plot(t, f(t), 'r');

%---v:(100, 200, 400, 800), s:100, st_iteracij:100 :: 2 NIT---OMP
hold on;
y = [67.7574, 133.3540, 265.8805, 532.4182]';
f = @(x) 7.8142e-01 + 6.6419e-05 * x;
plot(x, y, 'bo');
plot(t, f(t), 'b');

%---v:(100, 200, 400, 800), s:100, st_iteracij:100 :: 2 NIT---
y = [75.6012, 146.9035, 275.6618, 533.2712]';
f = @(x) 1.3903e+01 + 6.5055e-05 * x;
plot(x, y, 'go');
plot(t, f(t), 'g');

%---v:100, s:100, st_iteracij:(100, 200, 400, 800) :: ---OCL
y = [11.2383, 17.5298, 30.0514, 57.0633]';
f = @(x) 4.3903e+00 + 6.5548e-06 * x;
plot(x, y, 'ko');
plot(t, f(t), 'k');

ylabel('Cas[ms]');
xlabel('N');

hold off;
