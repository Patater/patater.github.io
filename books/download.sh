---
layout: null
---
#!/bin/sh

{% assign sorted = site.tags.book | sort: 'title' %}
{% for book in sorted %}
{% if book.isbn %}
echo -n "{{ book.isbn}}..."
wget -q -S http://covers.openlibrary.org/b/isbn/{{ book.isbn }}-S.jpg?default=false -O {{ book.isbn }}-S.jpg || rm {{ book.isbn }}-S.jpg
wget -q -S http://covers.openlibrary.org/b/isbn/{{ book.isbn }}-M.jpg?default=false -O {{ book.isbn }}-M.jpg || rm {{ book.isbn }}-M.jpg
wget -q -S http://covers.openlibrary.org/b/isbn/{{ book.isbn }}-L.jpg?default=false -O {{ book.isbn }}-L.jpg || rm {{ book.isbn }}-L.jpg
#curl http://covers.openlibrary.org/b/isbn/{{ book.isbn }}-S.jpg?default=false -o {{ book.isbn }}-S.jpg --fail
#curl http://covers.openlibrary.org/b/isbn/{{ book.isbn }}-M.jpg?default=false -o {{ book.isbn }}-M.jpg --fail
#curl http://covers.openlibrary.org/b/isbn/{{ book.isbn }}-L.jpg?default=false -o {{ book.isbn }}-L.jpg --fail
echo " done"
{% elsif book.iid %}
echo -n "{{ book.iid}}..."
wget -q -S http://covers.openlibrary.org/b/id/{{ book.iid }}-S.jpg?default=false -O {{ book.iid }}-S.jpg || rm {{ book.iid }}-S.jpg
wget -q -S http://covers.openlibrary.org/b/id/{{ book.iid }}-M.jpg?default=false -O {{ book.iid }}-M.jpg || rm {{ book.iid }}-M.jpg
wget -q -S http://covers.openlibrary.org/b/id/{{ book.iid }}-L.jpg?default=false -O {{ book.iid }}-L.jpg || rm {{ book.iid }}-L.jpg
#curl http://covers.openlibrary.org/b/id/{{ book.iid }}-S.jpg?default=false -o {{ book.iid }}-S.jpg --fail
#curl http://covers.openlibrary.org/b/id/{{ book.iid }}-M.jpg?default=false -o {{ book.iid }}-M.jpg --fail
#curl http://covers.openlibrary.org/b/id/{{ book.iid }}-L.jpg?default=false -o {{ book.iid }}-L.jpg --fail
echo " done"
{% elsif book.olid %}
echo -n "{{ book.id}}..."
wget -q -S http://covers.openlibrary.org/b/olid/{{ book.olid }}-S.jpg?default=false -O {{ book.olid }}-S.jpg || rm {{ book.olid }}-S.jpg
wget -q -S http://covers.openlibrary.org/b/olid/{{ book.olid }}-M.jpg?default=false -O {{ book.olid }}-M.jpg || rm {{ book.olid }}-M.jpg
wget -q -S http://covers.openlibrary.org/b/olid/{{ book.olid }}-L.jpg?default=false -O {{ book.olid }}-L.jpg || rm {{ book.olid }}-L.jpg
#curl http://covers.openlibrary.org/b/olid/{{ book.olid }}-S.jpg?default=false -o {{ book.olid }}-S.jpg --fail
#curl http://covers.openlibrary.org/b/olid/{{ book.olid }}-M.jpg?default=false -o {{ book.olid }}-M.jpg --fail
#curl http://covers.openlibrary.org/b/olid/{{ book.olid }}-L.jpg?default=false -o {{ book.olid }}-L.jpg --fail
echo " done"
{% endif %}
{% endfor %}
