#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command EnablePY is deprecated since 21.3. You may use EnablePYCodeForSV.
    /// 
    /// Tells if P(Y)-Code is enabled for the specified satellite PRN. See EnablePY description for allowed signals.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------
    /// Prn    int    Satellite PRN number
    /// Signal string Signal key - see command description for possible values
    ///

    class IsPYEnabled;
    typedef std::shared_ptr<IsPYEnabled> IsPYEnabledPtr;
    
    
    class IsPYEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsPYEnabled();

      IsPYEnabled(int prn, const std::string& signal);
  
      static IsPYEnabledPtr create(int prn, const std::string& signal);
      static IsPYEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);
    };
  }
}

