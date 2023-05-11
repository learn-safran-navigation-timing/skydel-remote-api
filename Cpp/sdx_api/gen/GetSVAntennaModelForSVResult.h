#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSVAntennaModelForSV.
    ///
    /// Name             Type   Description
    /// ---------------- ------ -----------------------------------------------------------------
    /// System           string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC".
    /// SvId             int    The satellite's SV ID.
    /// AntennaModelName string SV antenna model name.
    ///

    class GetSVAntennaModelForSVResult;
    typedef std::shared_ptr<GetSVAntennaModelForSVResult> GetSVAntennaModelForSVResultPtr;
    
    
    class GetSVAntennaModelForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVAntennaModelForSVResult();

      GetSVAntennaModelForSVResult(const std::string& system, int svId, const std::string& antennaModelName);

      GetSVAntennaModelForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& antennaModelName);

      static GetSVAntennaModelForSVResultPtr create(const std::string& system, int svId, const std::string& antennaModelName);

      static GetSVAntennaModelForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& antennaModelName);
      static GetSVAntennaModelForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** antennaModelName ****
      std::string antennaModelName() const;
      void setAntennaModelName(const std::string& antennaModelName);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetSVAntennaModelForSVResult);
  }
}

