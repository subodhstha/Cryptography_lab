from Cryptodome.Hash import SHA256

data = b"Hello, World!"

# Compute SHA256 hash
sha256_hash = SHA256.new(data)
print("SHA256 Hash: ", sha256_hash.hexdigest())