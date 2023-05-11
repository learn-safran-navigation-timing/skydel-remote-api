#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Apply reserved flag for a SBAS satellite
    ///
    /// Name   Type Description
    /// ------ ---- ---------------------------
    /// SvId   int  The satellite's SV ID
    /// Health bool The reserved unhealthy flag
    ///

    class SetSbasReservedHealthForSV;
    typedef std::shared_ptr<SetSbasReservedHealthForSV> SetSbasReservedHealthForSVPtr;
    
    
    class SetSbasReservedHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSbasReservedHealthForSV();

      SetSbasReservedHealthForSV(int svId, bool health);

      static SetSbasReservedHealthForSVPtr create(int svId, bool health);
      static SetSbasReservedHealthForSVPtr dynamicCast(CommandBasePtr ptr);
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

