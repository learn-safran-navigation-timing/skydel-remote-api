#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the SBAS degradation parameters for the specified service provider. By default, all degradation parameters are returned. If specific parameter names are provided, only those parameters are returned.
    ///
    /// Name                      Type         Description
    /// ------------------------- ------------ -----------------------------------------------------------------------------------------
    /// ServiceProvider           string       Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN", "SDCM", "BDSBAS" and "KASS".
    /// DegradationParameterArray array string An array of degradationparameters.
    ///                                        Accepted values are: "BRRC", "CLTC_LSB", "CLTC_V1", "ILTC_V1", "CLTC_V0",
    ///                                                             "ILTC_V0", "CGEO_LSB", "CGEO_V", "IGEO", "CER",
    ///                                                             "CIONO_STEP", "IIONO", "CIONO_RAMP", "RSSUDRE", "RSSIONO"
    ///                                                             and "CCOVARIANCE"
    ///

    class GetSbasDegradationParameters;
    typedef std::shared_ptr<GetSbasDegradationParameters> GetSbasDegradationParametersPtr;
    
    
    class GetSbasDegradationParameters : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSbasDegradationParameters();

      GetSbasDegradationParameters(const std::string& serviceProvider, const std::vector<std::string>& degradationParameterArray);

      static GetSbasDegradationParametersPtr create(const std::string& serviceProvider, const std::vector<std::string>& degradationParameterArray);
      static GetSbasDegradationParametersPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);


      // **** degradationParameterArray ****
      std::vector<std::string> degradationParameterArray() const;
      void setDegradationParameterArray(const std::vector<std::string>& degradationParameterArray);
    };
    
  }
}

