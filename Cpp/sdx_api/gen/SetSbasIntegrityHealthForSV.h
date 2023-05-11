#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Apply integrity flag for a SBAS satellite
    ///
    /// Name   Type Description
    /// ------ ---- ----------------------------
    /// SvId   int  The satellite's SV ID
    /// Health bool The integrity unhealthy flag
    ///

    class SetSbasIntegrityHealthForSV;
    typedef std::shared_ptr<SetSbasIntegrityHealthForSV> SetSbasIntegrityHealthForSVPtr;
    
    
    class SetSbasIntegrityHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSbasIntegrityHealthForSV();

      SetSbasIntegrityHealthForSV(int svId, bool health);

      static SetSbasIntegrityHealthForSVPtr create(int svId, bool health);
      static SetSbasIntegrityHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

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

