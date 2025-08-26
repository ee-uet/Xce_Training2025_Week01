module sqrt_binary #(
    parameter real PRECISION = 1e-6
)(
    input  logic clk,
    input  logic rst,
    input  logic start,
    input  real  x,
    output logic done,
    output real  result
);

    real low, high, mid;
    logic calculating;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            result      <= 0.0;
            done        <= 0;
            low         <= 0.0;
            high        <= 1.0; // Initialize high as a fixed value (1.0)
            mid         <= 0.0;
            calculating <= 0;
        end else begin
            if (start && !calculating) begin
                low         <= 0.0;
                high        <= 1.0; // Fixed high value, no conditions
                calculating <= 1;
                done        <= 0;
            end else if (calculating) begin
                mid <= (low + high) / 2.0;
                if ((high - low) < PRECISION) begin
                    result      <= mid;
                    done        <= 1;
                    calculating <= 0;
                end else if ((mid * mid) > x) begin
                    high <= mid;
                end else begin
                    low <= mid;
                end
            end
        end
    end

endmodule

