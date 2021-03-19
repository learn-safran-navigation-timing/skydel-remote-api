#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command BeiDouPerturbations is deprecated since 21.3. You may use Perturbations.
    /// 
    /// Set BeiDou orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------
    /// Prn  int    Satellite PRN number 1..30
    /// Crs  double Crs (meter)
    /// Crc  double Crc (meter)
    /// Cis  double Crs (rad)
    /// Cic  double Crc (rad)
    /// Cus  double Cus (rad)
    /// Cuc  double Cuc (rad)
    ///

    class SetBeiDouPerturbations;
    typedef std::shared_ptr<SetBeiDouPerturbations> SetBeiDouPerturbationsPtr;
    
    
    class SetBeiDouPerturbations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouPerturbations();

      SetBeiDouPerturbations(int prn, double crs, double crc, double cis, double cic, double cus, double cuc);
  
      static SetBeiDouPerturbationsPtr create(int prn, double crs, double crc, double cis, double cic, double cus, double cuc);
      static SetBeiDouPerturbationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** crs ****
      double crs() const;
      void setCrs(double crs);


      // **** crc ****
      double crc() const;
      void setCrc(double crc);


      // **** cis ****
      double cis() const;
      void setCis(double cis);


      // **** cic ****
      double cic() const;
      void setCic(double cic);


      // **** cus ****
      double cus() const;
      void setCus(double cus);


      // **** cuc ****
      double cuc() const;
      void setCuc(double cuc);
    };
  }
}

