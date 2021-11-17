#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetSbasHealthReserved is deprecated since 21.9. You may use SetSbasSVReservedHealth.
    /// 
    /// Apply reserved flag for a SBAS satellite
    ///
    /// Name   Type Description
    /// ------ ---- ---------------------------
    /// Prn    int  The satellite's PRN number
    /// Health bool The reserved unhealthy flag
    ///

    class SetSbasHealthReserved;
    typedef std::shared_ptr<SetSbasHealthReserved> SetSbasHealthReservedPtr;
    
    
    class SetSbasHealthReserved : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSbasHealthReserved();

      SetSbasHealthReserved(int prn, bool health);
  
      static SetSbasHealthReservedPtr create(int prn, bool health);
      static SetSbasHealthReservedPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
  }
}

