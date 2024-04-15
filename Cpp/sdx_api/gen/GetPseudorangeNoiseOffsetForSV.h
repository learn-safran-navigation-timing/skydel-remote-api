#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the satellite pseudorange noise constant offset.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------------------
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    /// SvId   int    Satellite SV ID.
    ///

    class GetPseudorangeNoiseOffsetForSV;
    typedef std::shared_ptr<GetPseudorangeNoiseOffsetForSV> GetPseudorangeNoiseOffsetForSVPtr;
    
    
    class GetPseudorangeNoiseOffsetForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetPseudorangeNoiseOffsetForSV();

      GetPseudorangeNoiseOffsetForSV(const std::string& system, int svId);

      static GetPseudorangeNoiseOffsetForSVPtr create(const std::string& system, int svId);
      static GetPseudorangeNoiseOffsetForSVPtr dynamicCast(CommandBasePtr ptr);
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
    };
    
  }
}

