from Cryptodome.Hash import MD4
data = b"Hello, World!"
# Compute MD4 hash
md4_hash = MD4.new(data)
print("MD4 Hash: ", md4_hash.hexdigest())