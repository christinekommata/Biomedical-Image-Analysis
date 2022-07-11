%askhsh3
%pws kano gaucianh eikona
sigma=64;
xc=rows/2;
yc=cols/2;
for x=1:rows
    for y=1:cols
        Gauss_img(x,y)=(1/(2*pi*(sigma^2)))*exp(-((x-xc)^2+(y-yc)^2)/(2*sigma^2));
    end
end
%to min sketo dinei to min se kthe grammh k meta se kathe sthlh 
Gauss_img= (Gauss_img-min(min(Gauss_img)))/(max(max(Gauss_img))-min(min(Gauss_img)));
%gia na paei sto kentro prepei na aferesw apo gramh k sthlh to lentro ths
%prepei na to kanonikopoihsw gt exei mikres times xrhsimopoiw sxesh
figure;
imshow(Gauss_img);
title('Gauss image');
