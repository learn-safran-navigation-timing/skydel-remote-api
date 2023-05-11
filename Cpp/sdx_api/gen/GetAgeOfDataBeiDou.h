#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get BeiDou Age of data, Ephemeris (AODE) and Age of data, Clock (AODC)
    ///
    /// 
    ///

    class GetAgeOfDataBeiDou;
    typedef std::shared_ptr<GetAgeOfDataBeiDou> GetAgeOfDataBeiDouPtr;
    
    
    class GetAgeOfDataBeiDou : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAgeOfDataBeiDou();

      static GetAgeOfDataBeiDouPtr create();
      static GetAgeOfDataBeiDouPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

