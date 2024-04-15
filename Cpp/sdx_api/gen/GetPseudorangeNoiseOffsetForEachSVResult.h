#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPseudorangeNoiseOffsetForEachSV.
    ///
    /// Name    Type         Description
    /// ------- ------------ --------------------------------------------------------------------------
    /// System  string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// Enabled array bool   If true, the offset is enabled (applied)
    /// Offset  array double The constant offset in metters
    ///

    class GetPseudorangeNoiseOffsetForEachSVResult;
    typedef std::shared_ptr<GetPseudorangeNoiseOffsetForEachSVResult> GetPseudorangeNoiseOffsetForEachSVResultPtr;
    typedef GetPseudorangeNoiseOffsetForEachSVResult GetAllSatellitesPseudorangeNoiseOffsetResult;
    typedef std::shared_ptr<GetAllSatellitesPseudorangeNoiseOffsetResult> GetAllSatellitesPseudorangeNoiseOffsetResultPtr;
    
    class GetPseudorangeNoiseOffsetForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetPseudorangeNoiseOffsetForEachSVResult();

      GetPseudorangeNoiseOffsetForEachSVResult(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset);

      GetPseudorangeNoiseOffsetForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset);

      static GetPseudorangeNoiseOffsetForEachSVResultPtr create(const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset);

      static GetPseudorangeNoiseOffsetForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled, const std::vector<double>& offset);
      static GetPseudorangeNoiseOffsetForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);


      // **** offset ****
      std::vector<double> offset() const;
      void setOffset(const std::vector<double>& offset);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetPseudorangeNoiseOffsetForEachSVResult);
  }
}

