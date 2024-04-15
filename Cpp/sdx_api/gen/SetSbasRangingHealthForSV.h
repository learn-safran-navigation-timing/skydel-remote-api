#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Apply ranging flag for a SBAS satellite
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------
    /// SvId   int  The satellite's SV ID
    /// Health bool The ranging unhealthy flag
    ///

    class SetSbasRangingHealthForSV;
    typedef std::shared_ptr<SetSbasRangingHealthForSV> SetSbasRangingHealthForSVPtr;
    
    
    class SetSbasRangingHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSbasRangingHealthForSV();

      SetSbasRangingHealthForSV(int svId, bool health);

      static SetSbasRangingHealthForSVPtr create(int svId, bool health);
      static SetSbasRangingHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
    
  }
}

