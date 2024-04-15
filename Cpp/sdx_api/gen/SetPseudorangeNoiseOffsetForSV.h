#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the satellite pseudorange noise constant offset.
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------------------------
    /// System  string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SvId    int    Satellite SV ID.
    /// Enabled bool   If true, the offset is enabled (applied)
    /// Offset  double The constant offset in metters
    ///

    class SetPseudorangeNoiseOffsetForSV;
    typedef std::shared_ptr<SetPseudorangeNoiseOffsetForSV> SetPseudorangeNoiseOffsetForSVPtr;
    
    
    class SetPseudorangeNoiseOffsetForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetPseudorangeNoiseOffsetForSV();

      SetPseudorangeNoiseOffsetForSV(const std::string& system, int svId, bool enabled, double offset);

      static SetPseudorangeNoiseOffsetForSVPtr create(const std::string& system, int svId, bool enabled, double offset);
      static SetPseudorangeNoiseOffsetForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


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
    
  }
}

