%F(x) = y
%vhodni podatki:
%	x je [nx1] vektor xi koordinat
%	y je [nx1] vektor yi koordinat
%	model je kazalec na funkcijo model npr.: $model = @(p, x) p(1) + p(2)*x;
%	k je stevilo neznanih parametrov funkcije model = numel(p)
%
%rezultat:
%	funkcija parametri(x, y, model, k) vrne vrstico[1xk] p z parametri funkcije,
%	izracunane po metodi najmanjsih kvadratov
%
%primer klica:
%	$model = @(p, x) p(1) + p(2).*x;		%y = a + bx
%	$p = parametri([0 1]', [1 1]', model, 2);	%(0,1), (1,1) -> y = 1 + 0*x = [1 0]
%----------------------------------------------------------------------------

function p = parametri(x, y, model, k)

%A je matrika koeficientov neznank sistema enacb
%y je vektor resitev sistema enacb
  
	A = [];
	I = eye(k);
	for i = 1:k
		A = [A model(I(i,:), x)];
	end
	p = (pinv(A)*y)';
	%p = ((((A'*A)^-1)*A')*y)';
	%p = (A'*A) \ (A'*y);
	%p = (A\y)';
	%a)
%		printf("a)\t\n");
%		printf("-- F(2030) = %f\t\n", model(p, 2030));
%		printf("-- F(2050) = %f\t\n", model(p, 2050));
%		n = 0;
%		m = 0;
%		for i = 0:1/365:1
%			n = n + model(p, 2030 + i);
%			m = m + model(p, 2050 + i);
%		end
%		printf("-- povprecno za 2030 = %f\t\n", n/365);
%		printf("-- povprecno za 2050 = %f\t\n", m/365);
	%b)
%		printf("b)\t\n");
%		printf("-- Amplituda letnega nihanja koncentracije CO2 je %f\t\n", sqrt(p(4)^2 + p(5)^2));		
	%c)
%		printf("c)\t\n");
%		vsota = 0;
%		razlika = 0;
%		for i = 1974:2014
%			razlika = razlika + 1;
%			vsota = vsota + (p(2) + 2*p(3)*i);
%		end		
%		printf("-- Povprecni letni prirastek koncentracije CO2 je %f\t\n", vsota/razlika);
%		printf("-- Povprecno se letni prirastek poveca za %f\t\n", 2*p(3));		
	%printf("_________________________________________________________\t\n");
  
	%plot(x, y, '.');
	%hold on
	%plot(x, model(p, x), '-');
  
%!test
%! model = @(p, x) p(1) + p(2).*x;
%! assert(parametri([0 1]', [1 1]', model, 2), [1, 0], eps)
%!test
%! model = @(p, x) p(1) + p(2)*x + p(3)*x.^2;
%! assert(parametri([-2 -1 0 1 2]', [4 1 0 1 4]', model, 3), [0 0 1], 10*eps)
%!test
%! model = @(p, x) p(1) + p(2).*x;
%! assert(parametri([0 1 2]', [3 6 9]', model, 2), [3 3], 10*eps)
%!test
%! model = @(p, x) p(1) + p(2)*x + p(3)*x.^2 + p(4)*x.^3;
%! assert(parametri([-1 -1/2 0 1/2 1]', [0 -2 -1 0 -2]', model, 4), [-1 3 0 -4], 10*eps)


end
