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
    /// Result of GetPseudorangeNoiseOffsetForSV.
    ///
    /// Name    Type   Description
    /// ------- ------ ----------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId    int    Satellite SV ID.
    /// Enabled bool   If true, the offset is enabled (applied)
    /// Offset  double The constant offset in metters
    ///

    class GetPseudorangeNoiseOffsetForSVResult;
    typedef std::shared_ptr<GetPseudorangeNoiseOffsetForSVResult> GetPseudorangeNoiseOffsetForSVResultPtr;
    
    
    class GetPseudorangeNoiseOffsetForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPseudorangeNoiseOffsetForSVResult();

      GetPseudorangeNoiseOffsetForSVResult(const std::string& system, int svId, bool enabled, double offset);

      GetPseudorangeNoiseOffsetForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled, double offset);

      static GetPseudorangeNoiseOffsetForSVResultPtr create(const std::string& system, int svId, bool enabled, double offset);

      static GetPseudorangeNoiseOffsetForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, bool enabled, double offset);
      static GetPseudorangeNoiseOffsetForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** offset ****
      double offset() const;
      void setOffset(double offset);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetPseudorangeNoiseOffsetForSVResult);
  }
}

