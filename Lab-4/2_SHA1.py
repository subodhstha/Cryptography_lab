from Cryptodome.Hash import SHA1

data = b"Hello, World!"

# Compute SHA1 hash
sha1_hash = SHA1.new(data)
print("SHA1 Hash: ", sha1_hash.hexdigest())