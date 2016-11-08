%p je vrstica parametrov
%x je stevilo ali vektor stevil
%funkcija vrne vrednost y za pripadajoci x
function y = model(p, x)
	y = (p(1) + p(2).*x)';
end
