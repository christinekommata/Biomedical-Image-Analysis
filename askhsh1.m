%orizw diastaseis tou pinaka
rows=250;
cols=260;

%askhsh1

%eikona (a)
img1=zeros(rows,cols);  %orizoume thn eikona
img1(:,cols/2)=255; %se oles tis grammes pairnw ta cols/2
figure;
imshow(img1);
title ('White stripe in the middle');

%eikona (b)
img2=zeros(rows,cols);  %orizoume thn eikona
img2(rows/2,:)=255; %se oles tis sthles pairnw ta rows/2
%invert image
img3=255-img2;
figure;
imshow(img3);
title ('White pic with black stripe in the middle');


%eikona (c)
img4=zeros(rows,cols);
img4(10:10:end,:) = 255;
img4_=255-img4;
figure;
imshow(img4_);
title('Picture with horizontal lines');




%eikona (d)
img5=zeros(rows,cols);
img5(:,5:5:end) = 255;
img5(5:5:end,:)=255;
img5_=255-img5;
figure;
imshow(img5_);
title('Picture with dots');


%eikona (e)
img6=zeros(rows,cols);
x1=mod(rand(),rows)*rows;
y1=mod(rand(),cols)*cols;
x2=mod(rand(),rows)*rows;
y2=mod(rand(),cols)*cols;
color=mod(rand(),255);

for i=1:rows
    for j=1:cols
        if ( i>=x1 && i<=x1+x2 && j>=y1 && j<=y1+y2)
            img6(i,j)=color;
        end
    end
end

img6=255*(img6-min(min(img6)))/(max(max(img6))-min(min(img6)));
img6= uint8(img6);
figure;
imshow(img6);
title('Image with random squares');


%eikona (st)
img7=zeros(rows,cols);
f=10;
for i=1:rows
    for j=1:cols
        img7(i,j)=(127+127*cos(2*pi*f*(i+j)/rows));
    end
end
img7=255*(img7-min(min(img7)))/(max(max(img7))-min(min(img7)));
img7=uint8(img7);
figure;
imshow(img7);
title ('Picture with diagonal stripes');


%eikona (z)
img8=zeros(rows,cols);
f=5;
for i=1:rows
    for j=1:cols
        img8(i,j)=(127+127*cos(2*pi*f*(i*j)/rows));
    end
end
img8=255*(img8-min(min(img8)))/(max(max(img8))-min(min(img8)));
img8=uint8(img8);
figure;
imshow(img8);
title('Picture with weird thingies');


%eikona (h)
f=10; %an valw mikrh syxnothta vgainei diaforetiko
r=1:rows;
c=cos(2*pi*f*r/rows)'; %xrhsh hmhtwnwn
img9= uint8(127*ones(rows,cols)+127*repmat(c,1,cols));
figure; %to panw deutero kommati einai h kampulh
imshow(img9);
title('White picture with black stripes');











