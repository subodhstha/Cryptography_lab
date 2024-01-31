from Cryptodome.Hash import MD5

data = b"Hello, World!"

# Compute MD5 hash
md5_hash = MD5.new(data)
print("MD5 Hash: ", md5_hash.hexdigest())