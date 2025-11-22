def generate_serial_key(name):
    name_bytes = name.encode('latin-1')
    name_length = len(name_bytes)
    
    if name_length == 0:
        hash_value = 0x55555555
        secondary_hash = 0xDEADC0DE
        character_count = 0
    else:
        negative_length = -name_length
        secondary_hash = 0xDEADC0DE
        hash_value = 0x55555555
        character_count = 0
        position = 0
        
        while position <= name_length:
            current_char = name_bytes[position] if position < name_length else 0
            if current_char == 0: 
                break
            
            if (current_char & 1) == 0:
                
                rotated_hash = ((hash_value << 0xC) | (hash_value >> 0x14)) & 0xFFFFFFFF
                hash_value = (rotated_hash ^ current_char) & 0xFFFFFFFF
                hash_value = (hash_value + 0x90F01234) & 0xFFFFFFFF
            else:
                
                rotated_hash = ((hash_value << 0x1D) | (hash_value >> 0x3)) & 0xFFFFFFFF
                hash_value = (rotated_hash + current_char) & 0xFFFFFFFF
                hash_value = (hash_value + 0xE5D4C3B3) & 0xFFFFFFFF
            
            
            temp_value = (secondary_hash + character_count) & 0xFFFFFFFF
            secondary_hash = (temp_value + negative_length) & 0xFFFFFFFF
            secondary_hash = (secondary_hash ^ temp_value) & 0xFFFFFFFF
            
            
            hash_value = (hash_value ^ secondary_hash) & 0xFFFFFFFF
            
            position += 1
            character_count += 1
    
    
    count_squared = (character_count * character_count) & 0xFFFFFFFF
    final_component = (count_squared << 8) & 0xFFFFFFFF
    final_component = (final_component - count_squared) & 0xFFFFFFFF
    
    rotated_final = ((hash_value << 0x1D) | (hash_value >> 0x3)) & 0xFFFFFFFF
    final_hash = (rotated_final + secondary_hash) & 0xFFFFFFFF
    final_hash = (final_hash ^ final_component) & 0xFFFFFFFF
    
    return f"{final_hash:08X}"


while True:
    name = input("Enter name: ").strip()
    if not name: 
        break
    serial = generate_serial_key(name)
    print(f"Name: {name} -> Serial: {serial}")
