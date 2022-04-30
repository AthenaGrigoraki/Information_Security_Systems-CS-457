Για τον otp αλγοριθμο εκανα μια συναρτηση get_key οπου παιρνει τυχαια κλειδι μεσω της rand και εκτυπωνεται σωστα σαν ascii και δεκαδικος αντιστοιχα.
Γινεται encrypt με one_time_pad_encr, και το decrypt σωστα με one_time_pad_dencr και φαινεται η εκτυπωση και των 2 οταν 
σαν επιλογη στην main βαλουμε να γινει ο otp. Εχω επισης υλοποιησει τον beaufort cipher καθως και affine cipher.
Δεν εχω υλοποιησει καλα την word decryption, feistel cipher και rail fence cipher. Αρχισα τον rail fence encryption απλως επαιρνε εξτρα γραμματα μετα απο 
καποιο σημειο και δεν καταλαβαινα γιατι.

Σαν εξτρα συναρτησεις εκτος απο get_key εκανα την get length που επιστρεφει το μηκος του string καθως και την mod_mult_Inverse
για το affine decryption που ζητειται.


Για beaufort,otp και affine μετα που βαζω το αντιστοιχο νουμερο για να διαλεξω αλγοριθμο με switch,κανω enter και βαζω το text κατευθειαν απο κατω με fgets.
Το enter αυτο οφειλεται στο \n που εχω βαλει στην scanf για να μπορει να δουλεψει μετα η fgets με το input που θα βαλω μετα το enter.

