 %p je vrstica parametrov
%x je stevilo ali vektor stevil
%funkcija vrne vrednost y za pripadajoci x
function y = model(p, x)
	A = ones(numel(x), 1);
	tmp = [A x x.^2 sin(x.*2*pi) cos(x.*2*pi)];
	y = (p*tmp')';
end