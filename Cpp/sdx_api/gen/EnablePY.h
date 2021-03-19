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
    /// Enable (or disable) P(Y)-Code for specified satellite PRN. Use PRN 0 to enabled/disable all satellites.
    /// Allowed signal keys: "L1P", "L2P"
    ///
    /// Name    Type   Description
    /// ------- ------ --------------------------------------------------------
    /// Prn     int    Satellite PRN number
    /// Signal  string Signal key - see command description for possible values
    /// Enabled bool   Enable P(Y)-Code if True.
    ///

    class EnablePY;
    typedef std::shared_ptr<EnablePY> EnablePYPtr;
    
    
    class EnablePY : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnablePY();

      EnablePY(int prn, const std::string& signal, bool enabled);
  
      static EnablePYPtr create(int prn, const std::string& signal, bool enabled);
      static EnablePYPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
  }
}

