f=fopen('test.dat', 'rb');
dims=fread(f,2,'int32');
data=fread(f,Inf,'uint8');
fclose(f);
imagesc(reshape(data,dims(1),dims(2)));
colormap(gray);
axis square;