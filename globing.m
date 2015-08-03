x = input('enter name of image on desktop ','s');
im = imread(x);
im = imresize(im,[32 120]);
b = im2bw(im);
%b =double(b);

imshow(b);

%M = your_matrix_with_image_data;
fid = fopen('output.txt', 'wt');


for i=1:size(b,2)
    fprintf(fid ,'%d', b(:,i));
   
    fprintf(fid ,'\n');
end

fclose(fid);