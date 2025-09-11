declare -A capitals
capitals=(
    ["Pakistan"]="Islamabad"
    ["Japan"]="Sialkot"
    ["India"]="Faislabad"
    ["China"]="Kasur"
)

function get_capital() {
    local country=$1
    if [[ -n "${capitals[$country]}" ]]; then # -n checks if the string is non-empty
        echo "The capital of $country is: ${capitals[$country]}"
    else
        echo "Something went wrong here !"
    fi
}        
echo "Enter a country name to find its capital:"
read country 

get_capital "$country" 