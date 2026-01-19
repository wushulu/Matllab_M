import os
import shutil

def cleanup_directory(target_dir):
    # Allowed extensions (lowercase)
    # Added .bat to allowing list so the script doesn't delete the batch file
    allowed_extensions = {'.md', '.m', '.slx', '.ioc', '.png', '.xlsx', '.py', '.ps1', '.bat'}
    
    print(f"Scanning directory: {target_dir}...")

    # 1. First pass: Delete 'slprj' directories explicitly
    # We walk topdown so we can remove 'slprj' from dirs preventing os.walk from entering it
    for root, dirs, files in os.walk(target_dir, topdown=True):
        if 'slprj' in dirs:
            slprj_path = os.path.join(root, 'slprj')
            try:
                print(f"Deleting directory tree: {slprj_path}")
                shutil.rmtree(slprj_path)
                dirs.remove('slprj') # Prevent walking into this deleted dir
            except Exception as e:
                print(f"Error deleting {slprj_path}: {e}")

    # 2. Second pass: Delete unwanted files
    for root, dirs, files in os.walk(target_dir):
        for file in files:
            file_path = os.path.join(root, file)
            _, ext = os.path.splitext(file)
            
            if ext.lower() not in allowed_extensions:
                try:
                    os.remove(file_path)
                    print(f"Deleted file: {file_path}")
                except Exception as e:
                    print(f"Error deleting {file_path}: {e}")

    # 3. Third pass: Delete empty directories (bottom-up)
    for root, dirs, files in os.walk(target_dir, topdown=False):
        for name in dirs:
            dir_path = os.path.join(root, name)
            # Check if directory exists (it might have been slprj deleted earlier) and is empty
            if os.path.exists(dir_path):
                try:
                    if not os.listdir(dir_path):
                        os.rmdir(dir_path)
                        print(f"Deleted empty directory: {dir_path}")
                except Exception as e:
                    print(f"Error deleting directory {dir_path}: {e}")

if __name__ == "__main__":
    target = os.getcwd()
    # target = r"d:\Work\Matlab\PMSM" # Uncomment to hardcode path if needed
    
    print("WARNING: This script will perform the following actions:")
    print("1. Delete ALL 'slprj' folders.")
    print("2. Delete ALL files EXCEPT: .md, .m, .slx, .ioc, .png, .xlsx, scripts")
    print("3. Delete empty folders.")
    
    confirm = input(f"\nCurrent directory is: {target}\nType 'yes' to proceed with deletion: ")
    if confirm.lower() == 'yes':
        cleanup_directory(target)
        print("\nCleanup complete.")
    else:
        print("\nOperation cancelled.")
    
    input("Press Enter to exit...")
