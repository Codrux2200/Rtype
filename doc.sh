FILE=doc/
if test -f "$FILE"; then
    echo "Deleting $FILE..."
    rm -rf $FILE
fi
doxygen Doxyfile
DOC=doc.html
if test -f "$DOC"; then
    echo "Deleting $DOC..."
    rm -rf $DOC
fi
ln -s doc/html/index.html doc.html
